#ifndef _stream_stack_channel_push_ansi_special_h
#define _stream_stack_channel_push_ansi_special_h

/**
 * @file	stream_stack_channel_push_ansi_special.h
 * @author	en2
 * @date	22-09-2020
 * @brief	
 * @details	
**/

#include "stream_stack_channel.h"

namespace stream::stack::channel::push::ansi
{

class Special : public Channel
{
public:
    Special(Pointer & pointer);
    ~Special();

    Special & a();
    Special & b();
    Special & r();
    Special & n();
    Special & t();
    Special & v();
    Special & f();

}; /* class: Special */

}; /* namespace: stream::stack::channel::push::ansi */

#endif /* define: stream_stack_channel_push_ansi_special_h */