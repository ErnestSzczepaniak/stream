#ifndef _stream_input_ansi_color_h
#define _stream_input_ansi_color_h

/**
 * @file	stream_input_ansi_color.h
 * @author	en2
 * @date	08-09-2020
 * @brief	
 * @details	
**/

#include "stream_pointer.h"

namespace stream::input::ansi
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

}; /* namespace: stream::input::ansi */

#endif /* define: stream_input_ansi_color_h */