#include "stream_stack_channel_pop.h"

namespace stream::stack::channel
{

Pop::Pop(char * start, char * stop) : Channel(start, stop)
{

}

Pop::~Pop()
{

}

int Pop::decimal(const char * delimiters)
{
    //auto * ptr = pointer.output(delimiters);

    //return strtol(ptr, nullptr, 10);
}

int Pop::hexadecimal(const char * delimiters)
{
    //auto * ptr = pointer.output(delimiters);

    //return strtol(ptr, nullptr, 16);
}

float Pop::floating(const char * delimiters)
{
    //auto * ptr = pointer.output(delimiters);

    //return strtof(ptr, nullptr);
}

char Pop::character(const char * delimiters)
{
    // return *pointer.output(delimiters);
}

char * Pop::word(const char * delimiters)
{
    // return pointer.output(delimiters);
}

char * Pop::text(const char * delimiters)
{
    // return pointer.output(delimiters);
}

void * Pop::data(int size)
{

}

}; /* namespace: stream::stack::channel */
