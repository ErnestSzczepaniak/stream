#ifndef _stream_stack_h
#define _stream_stack_h

/**
 * @file	stream_stack.h
 * @author	en2
 * @date	22-09-2020
 * @brief	
 * @details	
**/

//#include "stream_stack_set.h"
#include "stream_stack_channel_pop.h"
//#include "stream_stack_parse.h"

namespace stream
{

class Stack
{
    static constexpr auto size_buffer = 4096;

public:
    Stack();
    ~Stack();

    Stack & reset();

    int size();
    bool is_empty();
    bool is_full();

    Stack & operator=(Stack & other);

    //channel::Set set;
    stack::channel::Pop pop;
    //channel::Parse parse;

    char buffer[size_buffer];

}; /* class: Channel */

}; /* namespace: stream */

#endif /* define: stream_stack_h */