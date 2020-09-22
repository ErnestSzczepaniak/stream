#include "stream_channel_get.h"

namespace stream::channel
{

Get::Get(char * buffer, int size) : pointer(buffer, size)
{

}

Get::~Get()
{

}

char Get::character(const char * delimiters)
{
    return *pointer.output(delimiters);
}

char * Get::word(const char * delimiters)
{
    return pointer.output(delimiters);
}

char * Get::text(const char * delimiters)
{
    return pointer.output(delimiters);
}


}; /* namespace: stream::channel::action */
