#ifndef _stream_generic_h
#define _stream_generic_h

/**
 * @file	stream_generic.h
 * @author	en2
 * @date	10-09-2020
 * @brief	
 * @details	
**/

#include "stream_channel.h"

class Stream_generic
{
public:
    virtual int size() = 0;
    virtual stream::Channel * channel(int index = 0) = 0;

    Stream_generic & reset();

}; /* class: Stream_generic */


#endif /* define: stream_generic_h */