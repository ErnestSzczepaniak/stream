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
    static constexpr auto size_buffer = 1024;

public:
    Stream();
    ~Stream();


    Stream & reset();

    Stream & name(const char * value);
    const char * name();

    char * buffer();
    int size();
    int size_actual();

    Stream & operator=(Stream & other);

    stream::Output output;
    stream::Input input;

private:
    char _buffer[size_buffer];
    const char * _name = nullptr;
}; /* class: Stream */

#endif /* define: stream_h */