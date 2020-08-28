#ifndef _stream_channel_input_h
#define _stream_channel_input_h

/**
 * @file	stream_channel_input.h
 * @author	en2
 * @date	18-08-2020
 * @brief	
 * @details	
**/

#include "stream_channel.h"
#include "stdio.h"
#include "string.h"

class Stream_channel_input : public Stream_channel
{
public:
    template<typename ... Args>
    Stream_channel_input & format(const char * format, Args ... args);

    Stream_channel_input & integer(int value);
    Stream_channel_input & text(const char * text);

}; /* class: Stream_input */

template<typename ... Args>
Stream_channel_input & Stream_channel_input::format(const char * format, Args ... args)
{
    char temp[128];
    auto size_actual = 0;

    auto size = snprintf(temp, 128, format, args...);

    if (size <= buffer()->size_remaining()) size_actual = size;
    else if (size > buffer()->size_remaining()) size_actual = buffer()->size_remaining();

    memcpy(pointer.current(), temp, size_actual);

    pointer.move(size_actual);

    return *this;
}

#endif /* define: stream_channel_input_h */