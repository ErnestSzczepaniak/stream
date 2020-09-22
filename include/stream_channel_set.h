#ifndef _stream_channel_set_h
#define _stream_channel_set_h

/**
 * @file	stream_channel_set.h
 * @author	en2
 * @date	22-09-2020
 * @brief	
 * @details	
**/

#include "stream_channel_set_ansi.h"

namespace stream::channel
{

class Set
{
public:
    Set(char * buffer, int size);
    ~Set();

    template<typename ... Args>
    Set & format(const char * format, Args ... args);

    template<typename T> Set & decimal(T value, const char * delimiters = " ");
    template<typename T> Set & hexadecimal(T value, int digits = 8, const char * delimiters = " ");
    template<typename T> Set & floating(T value, int digits = 2, const char * delimiters = " ");

    Set & character(char value, const char * delimiters = " ");
    Set & word(char * value, const char * delimiters = " ");
    Set & text(char * value, const char * delimiters = " ");

    Pointer pointer;
    set::Ansi ansi;

}; /* class: Set */

template<typename ... Args>
Set & Set::format(const char * format, Args ... args)
{
    pointer.input(format, args...);

    return *this;
}

template<typename T> 
Set & Set::decimal(T value, const char * delimiters)
{
    pointer.input("%d%s", value, delimiters);

    return *this;
}

template<typename T> 
Set & Set::hexadecimal(T value, int digits, const char * delimiters)
{
    pointer.input("0x%0*x%s", digits, value, delimiters);

    return *this;
}

template<typename T>
Set & Set::floating(T value, int digits, const char * delimiters)
{
    pointer.input("%.*f%s", digits, value, delimiters);

    return *this;
}

}; /* namespace: stream::channel */

#endif /* define: stream_channel_set_h */