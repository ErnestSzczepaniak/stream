#include "stream_stack_channel_info.h"

namespace stream::stack::channel
{

Info::Info(char * start, char * stop) : pointer(start, stop)
{

}

Info::~Info()
{

}

int Info::offset(char * delimiters)
{
    return tools::string::get::size(pointer, delimiters);
}

int Info::count(char * word, const char * delimiters)
{
    return tools::string::count::word(pointer, word, delimiters);
}

int Info::words(const char * delimiters)
{
    return tools::string::count::words(pointer, delimiters);
}

int Info::lines()
{
    return tools::string::count::character(pointer, 10) + 1;
}

}; /* namespace: stream::stack::channel */
