#include "test.h"
#include "stream.h"

TEST_CASE("asd")
{
    Stream s;

    s.input.integer(10);

    auto w = s.output.integer(0);

}