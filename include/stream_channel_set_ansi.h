#ifndef _stream_input_ansi_h
#define _stream_input_ansi_h

/**
 * @file	stream_input_ansi.h
 * @author	en2
 * @date	08-09-2020
 * @brief	
 * @details	
**/

#include "stream_channel_set_ansi_clear.h"
#include "stream_channel_set_ansi_cursor.h"
#include "stream_channel_set_ansi_margins.h"
#include "stream_channel_set_ansi_scroll.h"
#include "stream_channel_set_ansi_font.h"
#include "stream_channel_set_ansi_color.h"
#include "stream_channel_set_ansi_special.h"

namespace stream::channel::set
{

class Ansi
{

public:
    Ansi(Pointer & pointer);
    ~Ansi();

    Ansi & reset();
    Ansi & size(int x, int y);
    Ansi & minimize();
    Ansi & maximize();

    ansi::Clear clear;
    ansi::Cursor cursor;
    ansi::Margins margins;
    ansi::Scroll scroll; 
    ansi::Font font;
    ansi::Color color;
    ansi::Special special;

private:
    Pointer & _pointer;

}; /* class: Ansi */

}; /* namespace: stream::input */

#endif /* define: stream_input_ansi_h */