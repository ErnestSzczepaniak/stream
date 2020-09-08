#ifndef _stream_h
#define _stream_h

/**
 * @file	stream.h
 * @author	en2
 * @date	17-08-2020
 * @brief	
 * @details	
**/

#include "stream_channel.h"

class Stream
{
public:
    Stream();

    Stream & reset();

    stream::Channel channel[2];

}; /* class: Stream */

#endif /* define: stream_h */