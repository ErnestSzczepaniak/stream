#ifndef _stream_channel_input_ansi_h
#define _stream_channel_input_ansi_h

/**
 * @file	stream_channel_input_ansi.h
 * @author	en2
 * @date	08-09-2020
 * @brief	
 * @details	
**/

#include "stream_channel_input_ansi_clear.h"
#include "stream_channel_input_ansi_cursor.h"
#include "stream_channel_input_ansi_margins.h"
#include "stream_channel_input_ansi_scroll.h"
#include "stream_channel_input_ansi_font.h"
#include "stream_channel_input_ansi_color.h"
#include "stream_channel_input_ansi_special.h"

namespace stream::channel::input
{

class Ansi
{

public:
    Ansi(Pointer & pointer);
    ~Ansi();

    ansi::Clear clear;
    ansi::Cursor cursor;
    ansi::Margins margins;
    ansi::Scroll scroll; 
    ansi::Font font;
    ansi::Color color;
    ansi::Special special;

}; /* class: Ansi */

}; /* namespace: stream::channel::input */

#endif /* define: stream_channel_input_ansi_h */