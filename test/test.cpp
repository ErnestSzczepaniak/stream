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

    s.output.set.decimal(10).decimal(430);

    s.flush();


    auto w = s.input.get.decimal();
    w = s.input.get.decimal();


}