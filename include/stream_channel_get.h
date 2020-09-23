#ifndef _stream_channel_get_h
#define _stream_channel_get_h

/**
 * @file	stream_channel_get.h
 * @author	en2
 * @date	22-09-2020
 * @brief	
 * @details	
**/

#include "stream_channel_pointer.h"
#include <string>

namespace stream::channel
{

class Get
{
public:
    Get(char * start, char * stop);
    ~Get();

    template<typename T = int> T decimal(const char * delimiters = " ");
    template<typename T = int> T hexadecimal(const char * delimiters = " "); 
    template<typename T = float> T floating(const char * delimiter = " ");

    char character(const char * delimiters = " ");
    char * word(const char * delimiters = " ");
    char * text(const char * delimiters = "\0");

    Pointer pointer;

}; /* class: Get */

template<typename T>
T Get::decimal(const char * delimiters)
{
    auto * ptr = pointer.output(delimiters);

    return strtol(ptr, nullptr, 10);
}

template<typename T>
T Get::hexadecimal(const char * delimiters)
{
    auto * ptr = pointer.output(delimiters);

    return strtol(ptr, nullptr, 16);
}

template<typename T>
T Get::floating(const char * delimiters)
{
    auto * ptr = pointer.output(delimiters);

    return strtof(ptr, nullptr);
}

}; /* namespace: stream::channel */

#endif /* define: stream_channel_get_h */