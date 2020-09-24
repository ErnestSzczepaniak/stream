#ifndef _stream_stack_channel_push_ansi_h
#define _stream_stack_channel_push_ansi_h

/**
 * @file	stream_stack_channel_push_ansi.h
 * @author	en2
 * @date	08-09-2020
 * @brief	
 * @details	
**/

#include "stream_stack_channel_push_ansi_clear.h"
#include "stream_stack_channel_push_ansi_cursor.h"
#include "stream_stack_channel_push_ansi_margins.h"
#include "stream_stack_channel_push_ansi_scroll.h"
#include "stream_stack_channel_push_ansi_font.h"
#include "stream_stack_channel_push_ansi_color.h"
#include "stream_stack_channel_push_ansi_special.h"

namespace stream::stack::channel::push
{

class Ansi : public Channel
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

}; /* class: Ansi */

}; /* namespace: stream::input */

#endif /* define: stream_stack_channel_push_ansi_h */