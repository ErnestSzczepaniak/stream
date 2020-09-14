#ifndef _stream_input_h
#define _stream_input_h

/**
 * @file	stream_input.h
 * @author	en2
 * @date	14-09-2020
 * @brief	
 * @details	
**/

#include "stream_pointer.h"
#include "stream_input_ansi.h"

namespace stream
{

class Input
{
public:
    Input(char * buffer, int size);

    template<typename ... Args>
    Input & format(const char * format, Args ... args);

    template<typename T> Input & decimal(T value, const char * delimiters = " ");
    template<typename T> Input & hexadecimal(T value, int digits = 8, const char * delimiters = " ");
    template<typename T> Input & floating(T value, int digits = 2, const char * delimiters = " ");

    Input & character(char value, const char * delimiters = " ");
    Input & word(char * value, const char * delimiters = " ");

    Pointer pointer;
    input::Ansi ansi;

}; /* class: Input */

template<typename ... Args>
Input & Input::format(const char * format, Args ... args)
{
    pointer_input(pointer, format, args...);

    return *this;
}

template<typename T> 
Input & Input::decimal(T value, const char * delimiters)
{
    return format("%d%s", value, delimiters);
}

template<typename T> 
Input & Input::hexadecimal(T value, int digits, const char * delimiters)
{
    return format("0x%0*x%s", digits, value, delimiters);
}

template<typename T>
Input & Input::floating(T value, int digits, const char * delimiters)
{
    return format("%.*f%s", digits, value, delimiters);
}

}; /* namespace: stream */

#endif /* define: stream_input_h */