#include "stream_channel_get.h"

namespace stream::channel
{

Get::Get(char * buffer, int size) : pointer(buffer, size)
{

}

Get::~Get()
{

}

char Get::character(int word, const char * delimiters)
{
    auto * ptr = pointer.output(word, delimiters);

    return *ptr;
}

char * Get::word(int word, const char * delimiters)
{
    auto * ptr = pointer.output(word, delimiters);

    return ptr;
}

}; /* namespace: stream::channel::action */
