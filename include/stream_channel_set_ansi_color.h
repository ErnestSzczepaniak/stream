#ifndef _stream_channel_set_ansi_color_h
#define _stream_channel_set_ansi_color_h

/**
 * @file	stream_channel_set_ansi_color.h
 * @author	en2
 * @date	22-09-2020
 * @brief	
 * @details	
**/

#include "stream_channel_pointer.h"

namespace stream::channel::set::ansi
{

class Color
{
public:
    Color(Pointer & pointer);
    ~Color();

    Color & foreground(int r, int g, int b);    
    Color & background(int r, int g, int b);

private:
    Pointer & _pointer;

}; /* class: Color */

}; /* namespace: stream::channel::set::ansi */

#endif /* define: stream_channel_set_ansi_color_h */