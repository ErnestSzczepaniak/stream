#include "test.h"
#include "stream.h"

void show_string(char * string)
{
    printf("%s", string);
    printf("\r\n");
}



TEST_CASE("asd")
{
    Stream s;

    //stream::channel::action:: action(nullptr, 2);

    s.input.set.text("a d -c w r |");

    auto * w = s.input.get.word();
    w = s.input.get.word();
    w = s.input.get.word();

    s.input.parse.is_present("-c");

}