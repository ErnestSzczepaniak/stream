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


    s.input.format("%s", "q1 q2 q3");

    auto pos = s.input.pointer.position();


    

    auto p = s.input.pointer.position();

}