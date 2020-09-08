#ifndef _stream_channel_input_ansi_clear_display_h
#define _stream_channel_input_ansi_clear_display_h

/**
 * @file	stream_channel_input_ansi_clear_display.h
 * @author	en2
 * @date	08-09-2020
 * @brief	
 * @details	
**/

#include "stream_pointer.h"

namespace stream::channel::input::ansi::clear
{

class Display
{

public:
    Display(Pointer & pointer);
    ~Display();

    Display & right();
    Display & left();
    Display & entire();    

protected:


private:
    Pointer & _pointer;

}; /* class: Display */


}; /* namespace: stream::channel::input::ansi::clear */


#endif /* define: stream_channel_input_ansi_clear_display_h */