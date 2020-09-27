#ifndef _stream_stack_h
#define _stream_stack_h

/**
 * @file	stream_stack.h
 * @author	en2
 * @date	22-09-2020
 * @brief	
 * @details	
**/

#include "stream_stack_channel_push.h"
#include "stream_stack_channel_pop.h"
#include "stream_stack_channel_parse.h"
#include "stream_stack_channel_info.h"

namespace stream
{

template<int size>
class Stack
{
public:
    Stack();
    ~Stack();

    Stack & clear();
    Stack & reset();

    int size_actual();
    bool is_empty();
    bool is_full();

    Stack & operator=(Stack & other);

    stack::channel::Push push;
    stack::channel::Pop pop;
    stack::channel::Parse parse;
    stack::channel::Info info;

    char buffer[size];

}; /* class: Channel */


template<int size>
Stack<size>::Stack()
:
push(buffer, buffer + size),
pop(buffer, buffer + size),
parse(buffer, buffer + size),
info(buffer, buffer + size)
{

}

template<int size>
Stack<size>::~Stack()
{

}

template<int size>
int Stack<size>::size_actual()
{
    return strlen(buffer);
}

template<int size>
bool Stack<size>::is_empty()
{
    return (buffer[0] == 0);
}

template<int size>
bool Stack<size>::is_full()
{
    return (buffer[size - 1] != 0);
}

template<int size>
Stack<size> & Stack<size>::reset()
{
    push.pointer.reset();
    pop.pointer.reset();
    parse.pointer.reset();

    return *this;
}

template<int size>
Stack<size> & Stack<size>::clear()
{
    reset();

    memset(buffer, 0, size);

    return *this;
}

template<int size>
Stack<size> & Stack<size>::operator=(Stack & other)
{
    push.pointer = other.push.pointer;
    pop.pointer = other.pop.pointer;
    parse.pointer = other.parse.pointer;

    memcpy(buffer, other.buffer, other.push.pointer.position());

    return *this;
}


}; /* namespace: stream */

#endif /* define: stream_stack_h */