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
    static constexpr auto size_control = 512;
    static constexpr auto size_io = 16384;

public:
    Stream();
    ~Stream();

    Stream & reset();
    Stream & clear();
    Stream & flush();

    stream::Stack<size_control> command;
    stream::Stack<size_io> input;
    stream::Stack<size_io> output;
    stream::Stack<size_control> error;

}; /* class: Stream */

#endif /* define: stream_h */