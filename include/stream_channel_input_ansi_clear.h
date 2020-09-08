#ifndef _stream_channel_input_ansi_clear_h
#define _stream_channel_input_ansi_clear_h

/**
 * @file	stream_channel_input_ansi_clear.h
 * @author	en2
 * @date	08-09-2020
 * @brief	
 * @details	
**/

#include "stream_channel_input_ansi_clear_display.h"
#include "stream_channel_input_ansi_clear_line.h"

namespace stream::channel::input::ansi
{

class Clear
{

public:
    Clear(Pointer & pointer);
    ~Clear();

    clear::Display display;
    clear::Line line;

protected:
    

private:
    

}; /* class: Clear */


}; /* namespace: stream::channel::input::ansi */


#endif /* define: stream_channel_input_ansi_clear_h */