#ifndef _stream_channel_input_ansi_clear_line_h
#define _stream_channel_input_ansi_clear_line_h

/**
 * @file	stream_channel_input_ansi_clear_line.h
 * @author	en2
 * @date	08-09-2020
 * @brief	
 * @details	
**/

#include "stream_pointer.h"

namespace stream::channel::input::ansi::clear
{

class Line
{

public:
    Line(Pointer & pointer);
    ~Line();

    Line & right();
    Line & left();
    Line & entire();    

private:
    Pointer & _pointer;

}; /* class: Line */


}; /* namespace: stream::channel::input::ansi::clear */


#endif /* define: stream_channel_input_ansi_clear_line_h */