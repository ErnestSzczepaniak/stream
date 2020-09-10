#ifndef _stream_channel_output_h
#define _stream_channel_output_h

/**
 * @file	stream_channel_output.h
 * @author	en2
 * @date	17-08-2020
 * @brief	
 * @details	
**/

#include "tools_string.h"
#include <string>
#include <type_traits>
#include "stream_pointer.h"

namespace stream::channel
{

class Output
{
public:
    Output(char * buffer, int size);
    ~Output();

    template<typename T = int> T decimal(int word = 0, const char * delimiters = " ");
    template<typename T = int> T hexadecimal(int word = 0, const char * delimiters = " "); 
    template<typename T = float> T floating(int word = 0, const char * delimiter = " ");

    char character(int word = 0, const char * delimiters = " ");
    char * word(int word = 0, const char * delimiters = " ");

    Pointer pointer;

}; /* class: Stream_channel_output */

template<typename T>
T Output::decimal(int word, const char * delimiters)
{
    auto * ptr = pointer_output(pointer, word, delimiters);

    return strtol(ptr, nullptr, 10);
}

template<typename T>
T Output::hexadecimal(int word, const char * delimiters)
{
    auto * ptr = pointer_output(pointer, word, delimiters);

    return strtol(ptr, nullptr, 16);
}

template<typename T>
T Output::floating(int word, const char * delimiters)
{
    auto * ptr = pointer_output(pointer, word, delimiters);

    return strtof(ptr, nullptr);
}

}; /* namespace: stream::channel */




#endif /* define: stream_channel_output_h */