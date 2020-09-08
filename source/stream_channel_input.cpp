#include "stream_channel_input.h"

namespace stream::channel
{

Input::Input(char * buffer, int size) : pointer(buffer, size), ansi(pointer)
{

}

Input & Input::word(char * value, const char * delimiters)
{
    return format("%s%s", value, delimiters);
}

Input & Input::character(char value, const char * delimiters)
{
    return format("%c%s", value, delimiters);
}

}; /* namespace: stream::channel */