#include "stream_output.h"
#include "tools_string.h"

namespace stream
{

Output::Output(char * buffer, int size) : Channel(buffer, size)
{

}

Output::~Output()
{

}

char Output::character(int word, const char * delimiters)
{
    auto * ptr = Pointer::output(pointer, word, delimiters);

    return *ptr;
}

char * Output::word(int word, const char * delimiters)
{
    return nullptr;
}

}; /* namespace: stream */


