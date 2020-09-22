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

    s.input.set.text("w1 10 20 30 | w2");

    auto * w = s.input.get.text("|");


}