#ifndef _stream_h
#define _stream_h

/**
 * @file	stream.h
 * @author	en2
 * @date	22-09-2020
 * @brief	
 * @details	
**/

#include "stream_stack.h"

class Stream
{
public:
    Stream();
    ~Stream();

    Stream & reset();
    Stream & flush();

    stream::Stack command;
    // stream::Channel input;
    // stream::Channel output;
    // stream::Channel error;

}; /* class: Stream */

#endif /* define: stream_h */