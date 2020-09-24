#include "test.h"
#include "stream.h"

void show_string(char * string)
{
    printf("%s", string);
    printf("\r\n");
}

struct K
{
    int k;
    char w;
};


TEST_CASE("asd")
{
    Stream s;

    s.command.push.text("asd -c 10 -a 0x1000 -o PV");

    auto c = s.command.parse.option("-c").decimal();
    auto a = s.command.parse.option("-a").hexadecimal();
    auto o = s.command.parse.option("-o").word();

    auto r = s.command.parse.option("-o").is_equal("PV");

}