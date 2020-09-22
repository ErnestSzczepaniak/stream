#ifndef _stream_channel_h
#define _stream_channel_h

/**
 * @file	stream_channel.h
 * @author	en2
 * @date	22-09-2020
 * @brief	
 * @details	
**/

#include "stream_channel_set.h"
#include "stream_channel_get.h"

namespace stream
{

class Channel
{
    static constexpr auto size_buffer = 4096;

public:
    Channel();
    ~Channel();

    Channel & reset();

    int size_max();
    int size_actual();

    Channel & operator=(Channel & other);

    channel::Set set;
    channel::Get get;

    char buffer[size_buffer];

}; /* class: Channel */


}; /* namespace: stream */


#endif /* define: stream_channel_h */