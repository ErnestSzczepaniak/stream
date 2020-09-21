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

    s.input.text("program 1 | program 2");

    auto * pipe = s.find.word("| ");

}