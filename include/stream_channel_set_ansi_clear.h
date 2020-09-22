#ifndef _stream_channel_set_ansi_clear_h
#define _stream_channel_set_ansi_clear_h

/**
 * @file	stream_channel_set_ansi_clear.h
 * @author	en2
 * @date	22-09-2020
 * @brief	
 * @details	
**/

#include "stream_channel_set_ansi_clear_display.h"
#include "stream_channel_set_ansi_clear_line.h"

namespace stream::channel::set::ansi
{

class Clear
{

public:
    Clear(Pointer & pointer);
    ~Clear();

    clear::Display display;
    clear::Line line;

}; /* class: Clear */

}; /* namespace: stream::channel::set::ansi */

#endif /* define: stream_channel_set_ansi_clear_h */