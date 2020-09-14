#ifndef _stream_input_ansi_cursor_h
#define _stream_input_ansi_cursor_h

/**
 * @file	stream_input_ansi_cursor.h
 * @author	en2
 * @date	08-09-2020
 * @brief	
 * @details	
**/

#include "stream_input_ansi_cursor_move.h"

namespace stream::input::ansi
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

}; /* namespace: stream::input::ansi */

#endif /* define: stream_input_ansi_cursor_h */