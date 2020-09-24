#ifndef _stream_stack_channel_push_ansi_clear_display_h
#define _stream_stack_channel_push_ansi_clear_display_h

/**
 * @file	stream_stack_channel_push_ansi_clear_display.h
 * @author	en2
 * @date	22-09-2020
 * @brief	
 * @details	
**/

#include "stream_stack_channel.h"

namespace stream::stack::channel::push::ansi::clear
{

class Display : public Channel
{

public:
    Display(Pointer & pointer);
    ~Display();

    Display & right();
    Display & left();
    Display & entire();    

}; /* class: Display */

}; /* namespace: stream::stack::channel::push::ansi::clear */

#endif /* define: stream_stack_channel_push_ansi_clear_display_h */