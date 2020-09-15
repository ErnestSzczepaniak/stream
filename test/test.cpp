#include "test.h"
#include "stream.h"
#include "stream_pointer.h"

void show_string(char * string)
{
    printf("%s", string);
    printf("\r\n");
}

TEST_CASE("asd")
{
    Stream s;


    s.input.format("%s", "asd");
    s.input.format("%d", 4);

    s.input.align_left();

    auto b = s.input.is_aligned();

    s.input.format("%d", 4);

    s.input.align_right();

    s.input.format("%d", 8);

}