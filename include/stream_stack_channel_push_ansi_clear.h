#ifndef _stream_stack_channel_push_ansi_clear_h
#define _stream_stack_channel_push_ansi_clear_h

/**
 * @file	stream_stack_channel_push_ansi_clear.h
 * @author	en2
 * @date	22-09-2020
 * @brief	
 * @details	
**/

#include "stream_stack_channel_push_ansi_clear_display.h"
#include "stream_stack_channel_push_ansi_clear_line.h"

namespace stream::stack::channel::push::ansi
{

class Clear
{

public:
    Clear(Pointer & pointer);
    ~Clear();

    clear::Display display;
    clear::Line line;

}; /* class: Clear */

}; /* namespace: stream::stack::channel::push::ansi */

#endif /* define: stream_stack_channel_push_ansi_clear_h */