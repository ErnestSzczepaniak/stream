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

// escape 27 91

enum class Mode : unsigned char
{
    INPUT,
    ESCAPE
}; /* enum: Mode */

enum class Control : unsigned char
{
    TAB = 9,
    ENTER = 10,
    ESCAPE_1 = 27,
    ESCAPE_DEL = 51,
    ESCAPE_UP = 65,
    ESCAPE_DOWN = 66,
    ESCAPE_RIGHT = 67,
    ESCAPE_LEFT = 68,
    ESCAPE_END = 70,
    ESCAPE_HOME = 72,
    ESCAPE_2 = 91,
    BACKSPACE = 127
}; /* enum: Control */

bool is_control(char character, Control control)
{
    return (character == (char) control);
}

void print(char * buffer, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%c", buffer[i]);
    }
    
    fflush(nullptr);
}


void handler_printable(char character, Stream & stream)
{
    stream.channel[0].input.character(character, "");
    stream.channel[1].input.word(stream.channel[0].input.pointer.current() - 1, "");
    if (stream.channel[0].input.pointer.is_aligned() == false) stream.channel[1].input.ansi.cursor.move.left(stream.channel[0].input.pointer.size_end() - stream.channel[0].input.pointer.size_current());
}

void handler_backspace(Stream & stream)
{
    if (stream.channel[0].input.pointer.size_current() == 0) return;

    auto size = stream.channel[0].input.pointer.size_end() - stream.channel[0].input.pointer.size_current();

    stream.channel[1].input.ansi.cursor.move.left(1);

    stream.channel[1].input.word(stream.channel[0].input.pointer.current());
    tools::string::trim::left::characters(stream.channel[0].input.pointer.current() - 1, 1);
    stream.channel[0].input.pointer.move(-1);

    stream.channel[1].input.pointer.move_end();
    stream.channel[1].input.word("");

    stream.channel[1].input.ansi.cursor.move.left(size + 2);
}

void handler_home(Stream & stream)
{
    if (stream.channel[0].input.pointer.size_current() == 0) return;

    auto size = stream.channel[0].input.pointer.size_current();
    stream.channel[0].input.pointer.move_start();
    stream.channel[1].input.ansi.cursor.move.left(size);
}

void handler_end(Stream & stream)
{
    if (stream.channel[0].input.pointer.is_aligned() == true) return;

    auto size = stream.channel[0].input.pointer.size_end() - stream.channel[0].input.pointer.size_current();
    stream.channel[0].input.pointer.move_end();
    stream.channel[1].input.ansi.cursor.move.right(size);
}

void handler_left(Stream & stream)
{
    if (stream.channel[0].input.pointer.size_current() == 0) return;
    
    stream.channel[0].input.pointer.move(-1);
    stream.channel[1].input.ansi.cursor.move.left(1);  
}

void handler_right(Stream & stream)
{
    if (stream.channel[0].input.pointer.is_aligned() == true)
    
    stream.channel[0].input.pointer.move(1);
    stream.channel[1].input.ansi.cursor.move.right(1);
}

void handler_del(Stream & stream)
{
    if (stream.channel[0].input.pointer.size_end() - stream.channel[0].input.pointer.size_current() > 0)
    {

    }
}

void handler_enter(Stream & stream)
{
    auto * text = "\n channel[0] stream = ";
    print((char *) text, strlen(text));
    print(stream.channel[0].output.pointer.start(), stream.channel[0].output.pointer.size_end());
    print("\n", 1);
    exit(1);
}

void handler_tab(Stream & stream)
{

}

using Handler = void (*)(Stream &, char);



TEST_CASE("shell")
{
    const char * tab[] = 
    {
        "\x1b\x5b\x9\0",
        "\x1b\x12"
    };


    Stream s;

    s.channel[0].reset();
    s.channel[0].input.word((char *) tab[0], "");

    s.channel[1].reset();

    enableRawMode();

    auto mode = Mode::INPUT;

    char character_last;

    while(1)
    {
        auto character_current = get();

        if (mode == Mode::INPUT)
        {
            if (character_current >= 32 && character_current < 127) // direct printable
            {
                handler_printable(character_current, s);
            }
            else if (is_control(character_current, Control::BACKSPACE))
            {
                handler_backspace(s);
            }
            else if (is_control(character_current, Control::TAB))
            {      
                handler_tab(s);
            }
            else if (is_control(character_current, Control::ENTER))
            {
                handler_enter(s);
            }
            else if (is_control(character_current, Control::ESCAPE_1))
            {
                mode = Mode::ESCAPE;
            }
        }
        else if (mode == Mode::ESCAPE)
        {
            if (is_control(character_current, Control::ESCAPE_HOME))
            {
                handler_home(s);
            }
            else if (is_control(character_current, Control::ESCAPE_END))
            {
                handler_end(s);
            }
            else if (is_control(character_current, Control::ESCAPE_LEFT))
            {
                handler_left(s);
            }
            else if (is_control(character_current, Control::ESCAPE_RIGHT))
            {
                handler_right(s);
            }
            else if (is_control(character_current, Control::ESCAPE_DEL))
            {
                handler_del(s);
            }

            if (is_control(character_last, Control::ESCAPE_2)) mode = Mode::INPUT;
        }

        print(s.channel[1].output.pointer.start(), s.channel[1].output.pointer.size_end());
        s.channel[1].reset();

        character_last = character_current;
    }
}