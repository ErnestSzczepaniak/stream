#ifndef _stream_h
#define _stream_h

/**
 * @file	stream.h
 * @author	en2
 * @date	17-08-2020
 * @brief	
 * @details	
**/

#include "stream_channel_input.h"
#include "stream_channel_output.h"

class Stream
{
public:
    Stream();

    Stream_channel_input input;
    Stream_channel_output output;

private:
    Stream_buffer _buffer;

}; /* class: Stream */

#endif /* define: stream_h */