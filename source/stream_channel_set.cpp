#include "stream_channel_set.h"

namespace stream::channel
{

Set::Set(char * buffer, int size) : pointer(buffer, size), ansi(pointer)
{

}

Set::~Set()
{

}

Set & Set::character(char value, const char * delimiters)
{
    pointer.input("%c%s", value, delimiters);

    return *this;
}

Set & Set::word(char * value, const char * delimiters)
{
    pointer.input("%s%s", value, delimiters);

    return *this;
}

Set & Set::text(char * value, const char * delimiters)
{
    pointer.input("%s%s", value, delimiters);

    return *this;
}

}; /* namespace: stream::channel::action */
