#ifndef _stream_stack_channel_push_ansi_margins_h
#define _stream_stack_channel_push_ansi_margins_h

/**
 * @file	stream_stack_channel_push_ansi_margins.h
 * @author	en2
 * @date	22-09-2020
 * @brief	
 * @details	
**/

#include "stream_stack_channel.h"

namespace stream::stack::channel::push::ansi
{

class Margins : public Channel
{
public:
    Margins(Pointer & pointer);
    ~Margins();

    Margins & horizontal(int from, int to);
    Margins & vertical(int from, int to);     

}; /* class: Margins */

}; /* namespace: stream::stack::channel::push::ansi */

#endif /* define: stream_stack_channel_push_ansi_margins_h */