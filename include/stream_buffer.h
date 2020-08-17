#ifndef _stream_buffer_h
#define _stream_buffer_h

/**
 * @file	stream_buffer.h
 * @author	en2
 * @date	17-08-2020
 * @brief	
 * @details	
**/

#include "stream_buffer_pointer.h"
#include "stdio.h"

class Stream_buffer
{
    static constexpr auto _size = 1024;

public:
    Stream_buffer();

    char * start();
    char * end();

    char at(int position = 0);
    Stream_buffer & at(int position, char value);

    int size_actual();
    int size_max();

    bool is_empty();
    bool is_full();

    Stream_buffer & reset();
    Stream_buffer & fill(char value);

    int read(char * buffer, int size);
    int write(char * buffer, int size);
    template<typename ...Args> int format(const char * format, Args ... args);

    Stream_buffer_pointer pointer_read;
    Stream_buffer_pointer pointer_write;

private:
    char _buffer[_size];

}; /* class: Stream_buffer */

template<typename ... Args>
int Stream_buffer::format(const char * format, Args ... args)
{
    char temp[128];

    auto size = snprintf(temp, 128, format, args ...);
    
    return write(temp, size);
}

#endif /* define: stream_buffer_h */