#ifndef _stream_input_h
#define _stream_input_h

/**
 * @file	stream_input.h
 * @author	en2
 * @date	17-08-2020
 * @brief	
 * @details	
**/

#include "stream_generic.h"
#include "stdio.h"
#include "string.h"

class Stream_input : public Stream_generic
{
public:
    template<typename ... Args>
    Stream_input & format(const char * format, Args ... args);

    template<typename T> Stream_input & decimal(T value);

    Stream_input & text(const char * value);
    Stream_input & character(char value);

}; /* class: Stream_input */

template<typename ... Args>
Stream_input & Stream_input::format(const char * format, Args ... args)
{
    char temp[128];
    auto size_actual = 0;

    auto size = snprintf(temp, 128, format, args...);

    if (size <= size_remaining()) size_actual = size;
    else if (size > size_remaining()) size_actual = size_remaining();

    memcpy(pointer.current(), temp, size_actual);

    pointer.move(size_actual);

    return *this;
}

template<typename T>
Stream_input & Stream_input::decimal(T value)
{
    return format("%d", value);
}

#endif /* define: stream_input_h */