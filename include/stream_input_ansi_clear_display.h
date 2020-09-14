#ifndef _stream_input_ansi_clear_display_h
#define _stream_input_ansi_clear_display_h

/**
 * @file	stream_input_ansi_clear_display.h
 * @author	en2
 * @date	08-09-2020
 * @brief	
 * @details	
**/

#include "stream_pointer.h"

namespace stream::input::ansi::clear
{

class Display
{

public:
    Display(Pointer & pointer);
    ~Display();

    Display & right();
    Display & left();
    Display & entire();    

private:
    Pointer & _pointer;

}; /* class: Display */

}; /* namespace: stream::input::ansi::clear */

#endif /* define: stream_input_ansi_clear_display_h */