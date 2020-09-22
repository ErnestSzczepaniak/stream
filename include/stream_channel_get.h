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
    Get(char * buffer, int size);
    ~Get();

    template<typename T = int> T decimal(int word = 0, const char * delimiters = " ");
    template<typename T = int> T hexadecimal(int word = 0, const char * delimiters = " "); 
    template<typename T = float> T floating(int word = 0, const char * delimiter = " ");

    char character(int word = 0, const char * delimiters = " ");
    char * word(int word = 0, const char * delimiters = " ");

    Pointer pointer;

}; /* class: Get */

template<typename T>
T Get::decimal(int word, const char * delimiters)
{
    auto * ptr = pointer.output(word, delimiters);

    return strtol(ptr, nullptr, 10);
}

template<typename T>
T Get::hexadecimal(int word, const char * delimiters)
{
    auto * ptr = pointer.output(word, delimiters);

    return strtol(ptr, nullptr, 16);
}

template<typename T>
T Get::floating(int word, const char * delimiters)
{
    auto * ptr = pointer.output(word, delimiters);

    return strtof(ptr, nullptr);
}

}; /* namespace: stream::channel */

#endif /* define: stream_channel_get_h */