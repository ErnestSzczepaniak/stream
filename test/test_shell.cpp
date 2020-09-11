#include "stream.h"
#include "test.h"
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

struct termios orig_termios;

void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}
void enableRawMode() 
{
  tcgetattr(STDIN_FILENO, &orig_termios);
  atexit(disableRawMode);
  struct termios raw = orig_termios;
  raw.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
  system("clear");
}
char get()
{
    char temp;

    read(STDIN_FILENO, &temp, 1);

    return temp;
}

void print(stream::Channel * channel)
{
    auto * ptr = channel->input.pointer.start();
    printf("%s", channel->input.pointer.start());
    
    fflush(nullptr);
}

void handler_enter(Stream_generic & stream)
{
    printf("\n");
    print(stream.channel(1));
    printf("\n");
    exit(1);
}

void handler_printable(Stream_generic & stream)
{
    stream.channel(1)->input.character(stream.channel(0)->output.character(), "");
    stream.channel(2)->input.word(stream.channel(1)->input.pointer.current() - 1, "");
    if (stream.channel(1)->input.pointer.is_aligned() == false) stream.channel(2)->input.ansi.cursor.move.left(stream.channel(1)->input.pointer.size_end() - stream.channel(1)->input.pointer.size_current());

    stream.channel(0)->reset();
}

void handler_backspace(Stream_generic & stream)
{
    stream.channel(0)->reset();

    if (stream.channel(1)->input.pointer.size_current() == 0) return;

    auto size = stream.channel(1)->input.pointer.size_end() - stream.channel(1)->input.pointer.size_current();

    stream.channel(2)->input.ansi.cursor.move.left(1);

    stream.channel(2)->input.word(stream.channel(1)->input.pointer.current());
    tools::string::trim::left::characters(stream.channel(1)->input.pointer.current() - 1, 1);
    stream.channel(1)->input.pointer.move(-1);

    stream.channel(2)->input.pointer.move_end();
    stream.channel(2)->input.word("");

    stream.channel(2)->input.ansi.cursor.move.left(size + 2);

}

void handler_home(Stream_generic & stream)
{
    stream.channel(0)->reset();

    if (stream.channel(1)->input.pointer.size_current() == 0) return;

    auto size = stream.channel(1)->input.pointer.size_current();
    stream.channel(1)->input.pointer.move_start();
    stream.channel(2)->input.ansi.cursor.move.left(size);
}

void handler_end(Stream_generic & stream)
{
    stream.channel(0)->reset();

    if (stream.channel(1)->input.pointer.is_aligned() == true) return;

    auto size = stream.channel(1)->input.pointer.size_end() - stream.channel(1)->input.pointer.size_current();
    stream.channel(1)->input.pointer.move_end();
    stream.channel(2)->input.ansi.cursor.move.right(size);
}

void handler_left(Stream_generic & stream)
{
    stream.channel(0)->reset();

    if (stream.channel(1)->input.pointer.size_current() == 0) return;

    stream.channel(1)->input.pointer.move(-1);
    stream.channel(2)->input.ansi.cursor.move.left(1);  
}

void handler_right(Stream_generic & stream)
{
    stream.channel(0)->reset();

    if (stream.channel(1)->input.pointer.is_aligned() == true) return;

    stream.channel(1)->input.pointer.move(1);
    stream.channel(2)->input.ansi.cursor.move.right(1);
}

void handler_up(Stream_generic & stream)
{

}

void handler_down(Stream_generic & stream)
{

}

void handler_delete(Stream_generic & stream)
{
    stream.channel(0)->reset();

    if (stream.channel(1)->input.pointer.is_aligned() == true) return;

    auto size = stream.channel(1)->input.pointer.size_end() - stream.channel(1)->input.pointer.size_current();

    stream.channel(2)->input.word(stream.channel(1)->input.pointer.current() + 1);
    tools::string::trim::left::characters(stream.channel(1)->input.pointer.current(), 1);

    stream.channel(2)->input.pointer.move_end();
    stream.channel(2)->input.word("");

    stream.channel(2)->input.ansi.cursor.move.left(size + 1);
}

enum class Mode : unsigned char
{
    INPUT,
    ESCAPE
}; /* enum: Mode */

using Handler_escape = void (*)(Stream_generic &);

Handler_escape table_handler[] = 
{
    handler_home,
    handler_end,
    handler_left,
    handler_right,
    handler_up,
    handler_down,
    handler_delete
};

char table_escape[][5] = 
{
    {27, 91, 72, 0, 0}, // home
    {27, 91, 70, 0, 0}, // end
    {27, 91, 68, 0, 0}, // left
    {27, 91, 67, 0, 0}, // right
    {27, 91, 65, 0, 0}, // up
    {27, 91, 66, 0, 0}, // down
    {27, 91, 51, 126, 0} // delete
};

TEST_CASE("shell")
{
    auto rows = 2;
    auto columns = 5;

    enableRawMode();

    Stream<3> stream;
    stream.reset();

    stream.channel(0)->input.ansi.reset().size(64, 128);
    print(stream.channel(0));
    stream.channel(0)->reset();

    Mode mode = Mode::INPUT;


    auto limit = 20;

    while(1)
    {
        auto character = get();

        stream.channel(0)->input.character(character, "");

        if (character == 10) handler_enter(stream);
        else if (character == 27) mode = Mode::ESCAPE;
        else if (character >= 32 && character < 127 && mode == Mode::INPUT)
        {
            if (stream.channel(1)->input.pointer.size_end() < limit) handler_printable(stream);
            else stream.channel(0)->reset();
        } 
        else if (character == 127 && mode == Mode::INPUT) handler_backspace(stream);
        else
        {
            for (int i = 0; i < sizeof(table_escape) / 5; i++)
            {
                if (stream.channel(0)->info.compare.difference(&table_escape[i][0], 0, "") == 0)
                {
                    table_handler[i](stream);
                    mode = Mode::INPUT;
                    break; 
                }
            }
        }
        
        if (stream.channel(2)->input.pointer.size_end() > 0)
        {
            print(stream.channel(2));
            stream.channel(2)->reset();
        }
    }
}