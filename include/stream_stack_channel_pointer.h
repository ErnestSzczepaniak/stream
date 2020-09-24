#ifndef _stream_stack_channel_pointer_h
#define _stream_stack_channel_pointer_h

/**
 * @file	stream_stack_channel_pointer.h
 * @author	en2
 * @date	22-09-2020
 * @brief	
 * @details	
**/

#include "tools_string.h"

namespace stream::stack::channel
{

class Pointer
{
public:
    Pointer(char * start, char * stop);
    ~Pointer();

    Pointer & start(char * value);
    char * start();

    Pointer & stop(char * value);
    char * stop();

    Pointer & limit(char * value);
    char * limit();

    Pointer & position(int value);
    int position();

    int span();

    Pointer & move(int value);
    Pointer & reset();

    operator char *();
    char operator*();
    Pointer & operator=(char * value);
    Pointer & operator=(Pointer & other);

private:
    char * _start;
    char * _stop;
    char * _current;
    char * _limit;

}; /* class: Pointer */

}; /* namespace: stream::stack::channel */

#endif /* define: stream_stack_channel_pointer_h */