#ifndef _stream_h
#define _stream_h

/**
 * @file	stream.h
 * @author	en2
 * @date	17-08-2020
 * @brief	
 * @details	
**/

#include "stream_generic.h"

template<int channels>
class Stream : public Stream_generic
{
public:
    Stream() {}

    int size();
    stream::Channel * channel(int index = 0);

private:
    stream::Channel _channel[channels];

}; /* class: Stream */

template<int channels>
int Stream<channels>::size()
{
    return channels;
}

template<int channels>
stream::Channel * Stream<channels>::channel(int index)
{
    return (index < channels) ? &_channel[index] : nullptr;
}

#endif /* define: stream_h */