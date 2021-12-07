#include "stream_stack_channel_pop.h"
#include <string>

namespace stream::stack::channel
{

Pop::Pop(char * start, char * stop) : pointer(start, stop), Channel(pointer)
{

}

Pop::~Pop()
{

}

unsigned int Pop::decimal(const char * delimiters)
{
    auto * ptr = _output_format(delimiters);

    return strtoul(ptr, nullptr, 10);
}

unsigned int Pop::hexadecimal(const char * delimiters)
{
    auto * ptr = _output_format(delimiters);

    return strtoul(ptr, nullptr, 16);
}

float Pop::floating(const char * delimiters)
{
    auto * ptr = _output_format(delimiters);

    return strtof(ptr, nullptr);
}

char Pop::character(const char * delimiters)
{
    return *_output_format(delimiters);
}

char * Pop::word(const char * delimiters)
{
    return _output_format(delimiters);
}

char * Pop::text(const char * delimiters)
{
    return _output_format(delimiters);
}

char * Pop::line()
{
    return _output_format("\n");
}

void * Pop::data(int size)
{
    return _output_data(size);
}

}; /* namespace: stream::stack::channel */
