#ifndef _stream_channel_input_ansi_cursor_move_h
#define _stream_channel_input_ansi_cursor_move_h

/**
 * @file	stream_channel_input_ansi_cursor_move.h
 * @author	en2
 * @date	08-09-2020
 * @brief	
 * @details	
**/

#include "stream_pointer.h"

namespace stream::channel::input::ansi::cursor
{

class Move
{
public:
    Move(Pointer & pointer);
    ~Move();

    Move & home();
    Move & up(int value = 1);
    Move & down(int value = 1);
    Move & right(int value = 1);
    Move & left(int value = 1);
    Move & down_start(int value = 1);
    Move & up_start(int value = 1);
    Move & column(int value);
    Move & at(int x, int y);

private:
    Pointer & _pointer;    

}; /* class: Move */


}; /* namespace: stream::channel::input::ansi::cursor */


#endif /* define: stream_channel_input_ansi_cursor_move_h */