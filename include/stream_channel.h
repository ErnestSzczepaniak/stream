#ifndef _stream_channel_h
#define _stream_channel_h

/**
 * @file	stream_channel.h
 * @author	en2
 * @date	18-08-2020
 * @brief	
 * @details	
**/

#include "stream_channel_input.h"
#include "stream_channel_output.h"

namespace stream
{

class Channel
{
    static constexpr auto size_buffer = 1024;

public:
    Channel();
    ~Channel();

    Channel & reset();

    channel::Input input;
    channel::Output output;

private:
    char _buffer[size_buffer];
    
}; /* class: Stream_channel */

}; /* namespace: stream */




#endif /* define: _stream_channel_h */