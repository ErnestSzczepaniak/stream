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
    char test[48];
    
    stream::Pointer p(test, 48);

    p += 47;

    p++;

}