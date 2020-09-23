#ifndef _stream_stack_channel_h
#define _stream_stack_channel_h

/**
 * @file	stream_stack_channel.h
 * @author	en2
 * @date	23-09-2020
 * @brief	
 * @details	
**/

#include "stream_stack_channel_pointer.h"

namespace stream::stack
{

class Channel
{
public:
    Channel(char * start, char * stop);
    ~Channel();

    channel::Pointer pointer;

protected:
    template<typename ...Args> void input(const char * format, Args ... args) {}
    char * output(const char * delimiters) {}

}; /* class: Channel */

}; /* namespace: stream::stack */

#endif /* define: stream_stack_channel_h */