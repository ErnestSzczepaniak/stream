#ifndef _stream_stack_channel_push_ansi_cursor_h
#define _stream_stack_channel_push_ansi_cursor_h

/**
 * @file	stream_stack_channel_push_ansi_cursor.h
 * @author	en2
 * @date	22-09-2020
 * @brief	
 * @details	
**/

#include "stream_stack_channel_push_ansi_cursor_move.h"

namespace stream::stack::channel::push::ansi
{

class Cursor : public Channel
{
public:
    Cursor(Pointer & pointer);
    ~Cursor();

    Cursor & save();
    Cursor & restore();
    Cursor & show();
    Cursor & hide();

    cursor::Move move;   

}; /* class: Cursor */

}; /* namespace: stream::stack::channel::push::ansi */

#endif /* define: stream_stack_channel_push_ansi_cursor_h */