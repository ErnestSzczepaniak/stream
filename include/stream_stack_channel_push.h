#ifndef _stream_stack_channel_push_h
#define _stream_stack_channel_push_h

/**
 * @file	stream_stack_channel_push.h
 * @author	en2
 * @date	22-09-2020
 * @brief	
 * @details	
**/

#include "stream_stack_channel_push_ansi.h"

namespace stream::stack::channel
{

class Push : public Channel
{
public:
    Push(char * start, char * stop);
    ~Push();

    template<typename ... Args> Push & format(const char * format, Args ... args);
    template<typename T> Push & variable(T & variable);

    Push & decimal(unsigned int value, const char * delimiters = " ");
    Push & hexadecimal(unsigned int value, int digits = 8, const char * delimiters = " ");
    Push & floating(float value, int digits = 2, const char * delimiters = " ");

    Push & character(char value, const char * delimiters = " ");
    Push & word(char * value, const char * delimiters = " ");
    Push & text(char * value, const char * delimiters = "\0");
    Push & data(void * value, int size);

    Pointer pointer;
    push::Ansi ansi;

}; /* class: Set */

template<typename ... Args>
Push & Push::format(const char * format, Args ... args)
{
    _input_format(format, args...);

    return *this;
}

template<typename T>
Push & Push::variable(T & variable)
{
    return data(&variable, sizeof(T));
}

}; /* namespace: stream::channel */

#endif /* define: stream_stack_channel_push_h */