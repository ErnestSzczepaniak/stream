#ifndef _stream_stack_channel_pop_h
#define _stream_stack_channel_pop_h

/**
 * @file	stream_stack_channel_pop.h
 * @author	en2
 * @date	22-09-2020
 * @brief	
 * @details	
**/

#include "stream_stack_channel.h"

namespace stream::stack::channel
{

class Pop : public Channel
{
public:
    Pop(char * start, char * stop);
    ~Pop();

    template<typename T> T variable();

    int decimal(const char * delimiters = " ");
    int hexadecimal(const char * delimiters = " "); 
    float floating(const char * delimiter = " ");
    char character(const char * delimiters = " ");

    char * word(const char * delimiters = " ");
    char * text(const char * delimiters = "\0");
    void * data(int size);

    Pointer pointer;

}; /* class: Pop */

template<typename T>
T Pop::variable()
{
    if (auto * ptr = (T*) data(sizeof(T)); ptr != nullptr) return *ptr;
    else return {};
}

}; /* namespace: stream::channel */

#endif /* define: stack_stream_get_h */