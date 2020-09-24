#ifndef _stream_stack_channel_push_ansi_scroll_h
#define _stream_stack_channel_push_ansi_scroll_h

/**
 * @file	stream_stack_channel_push_ansi_scroll.h
 * @author	en2
 * @date	22-09-2020
 * @brief	
 * @details	
**/

#include "stream_stack_channel.h"

namespace stream::stack::channel::push::ansi
{

class Scroll : public Channel
{
public:
    Scroll(Pointer & pointer);
    ~Scroll();

    Scroll & up();
    Scroll & down();

}; /* class: Scroll */

}; /* namespace: stream::stack::channel::push::ansi */

#endif /* define: stream_stack_channel_push_ansi_scroll_h */