#ifndef _stream_stack_channel_push_ansi_clear_line_h
#define _stream_stack_channel_push_ansi_clear_line_h

/**
 * @file	stream_stack_channel_push_ansi_clear_line.h
 * @author	en2
 * @date	22-09-2020
 * @brief	
 * @details	
**/

#include "stream_stack_channel.h"

namespace stream::stack::channel::push::ansi::clear
{

class Line : public Channel
{

public:
    Line(Pointer & pointer);
    ~Line();

    Line & right();
    Line & left();
    Line & entire();    

}; /* class: Line */

}; /* namespace: stream::stack::channel::push::ansi::clear */

#endif /* define: stream_stack_channel_push_ansi_clear_line_h */