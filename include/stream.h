#ifndef _stream_h
#define _stream_h

/**
 * @file	stream.h
 * @author	en2
 * @date	17-08-2020
 * @brief	
 * @details	
**/

#include "stream_output.h"
#include "stream_input.h"

class Stream
{
    static constexpr auto size_buffer = 64;

public:
    Stream();
    ~Stream();

    int size_max();
    int size_actual();
    
    Stream & reset();

    Stream & operator=(Stream & other);
    bool operator==(Stream & other);
    bool operator!=(Stream & other);

    stream::Output output;
    stream::Input input;
    char buffer[size_buffer];

}; /* class: Stream */

#endif /* define: stream_h */