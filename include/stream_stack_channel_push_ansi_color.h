#ifndef _stream_stack_channel_push_ansi_color_h
#define _stream_stack_channel_push_ansi_color_h

/**
 * @file	stream_stack_channel_push_ansi_color.h
 * @author	en2
 * @date	22-09-2020
 * @brief	
 * @details	
**/

#include "stream_stack_channel.h"

namespace stream::stack::channel::push::ansi
{

class Color : public Channel
{
public:
    Color(Pointer & pointer);
    ~Color();

    Color & foreground(int r, int g, int b);    
    Color & background(int r, int g, int b);

}; /* class: Color */

}; /* namespace: stream::stack::channel::push::ansi */

#endif /* define: stream_stack_channel_push_ansi_color_h */