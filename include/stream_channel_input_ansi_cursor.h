#ifndef _stream_channel_input_ansi_cursor_h
#define _stream_channel_input_ansi_cursor_h

/**
 * @file	stream_channel_input_ansi_cursor.h
 * @author	en2
 * @date	08-09-2020
 * @brief	
 * @details	
**/

#include "stream_channel_input_ansi_cursor_move.h"

namespace stream::channel::input::ansi
{

class Cursor
{
public:
    Cursor(Pointer & pointer);
    ~Cursor();

    Cursor & save();
    Cursor & restore();
    Cursor & show();
    Cursor & hide();

    cursor::Move move;   

private:
    Pointer & _pointer;

}; /* class: Cursor */


}; /* namespace: stream::channel::input::ansi */


#endif /* define: stream_channel_input_ansi_cursor_h */