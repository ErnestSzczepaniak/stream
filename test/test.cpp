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

    s.command.push.text("sample | ww");



}