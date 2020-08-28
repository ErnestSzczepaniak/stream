#ifndef _stream_channel_h
#define _stream_channel_h

/**
 * @file	stream_channel.h
 * @author	en2
 * @date	18-08-2020
 * @brief	
 * @details	
**/

#include "stream_buffer.h"
#include "stream_pointer.h"

class Stream_channel
{
public:
    Stream_buffer * buffer();
    Stream_channel & buffer(Stream_buffer * buffer);

    Stream_pointer pointer;   

private:
    Stream_buffer * _buffer = nullptr;

}; /* class: Stream_channel */


#endif /* define: stream_channel_h */