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

    Pointer & position(int value);
    int position();

    Pointer & reset();
    Pointer & save();
    Pointer & restore();

    operator char *();
    char operator*();
    Pointer & operator++(int);
    Pointer & operator--(int);
    Pointer & operator+=(int value);
    Pointer & operator-=(int value);
    Pointer & operator=(char * value);
    Pointer & operator=(Pointer & other);

protected:
    Pointer & _move(int value);

private:
    char * _start;
    char * _stop;
    char * _current;

    char * _stash[3];

}; /* class: Pointer */

}; /* namespace: stream::stack::channel */

#endif /* define: stream_stack_channel_pointer_h */