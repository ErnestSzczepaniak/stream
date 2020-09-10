#include "test.h"
#include "stream.h"

void show_string(char * string)
{
    printf("%s", string);
    printf("\r\n");
}

void handle(Stream * stream)
{
}



TEST_CASE("asd")
{
    Stream s;

    s.channel[0].input.decimal(-1);

    auto w = s.channel[0].output.decimal();





    s.channel[0].input.floating(1.23);

    auto f = s.channel[0].output.floating();

    s.channel[0].input.hexadecimal(255, 2);

    auto h = s.channel[0].output.hexadecimal(); 

    // show_string(s.channel[0].input.pointer.start());

    // s.channel[0].input.word("sample_program").word("calculate").decimal(10).hexadecimal(10);

    // auto w = s.channel[0].output.hexadecimal();

}