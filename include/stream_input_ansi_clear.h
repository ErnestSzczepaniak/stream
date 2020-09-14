#ifndef _stream_input_ansi_clear_h
#define _stream_input_ansi_clear_h

/**
 * @file	stream_input_ansi_clear.h
 * @author	en2
 * @date	08-09-2020
 * @brief	
 * @details	
**/

#include "stream_input_ansi_clear_display.h"
#include "stream_input_ansi_clear_line.h"

namespace stream::input::ansi
{

class Clear
{

public:
    Clear(Pointer & pointer);
    ~Clear();

    clear::Display display;
    clear::Line line;

}; /* class: Clear */

}; /* namespace: stream::input::ansi */

#endif /* define: stream_input_ansi_clear_h */