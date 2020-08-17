#include "test.h"
#include "stream.h"

TEST_CASE("asd")
{
    Stream s;

    s.input.pointer.position();

    s.input.format("%s", "siema");

    s.input.decimal(10);


    printf("%s\n", s.input.pointer.initial());
}