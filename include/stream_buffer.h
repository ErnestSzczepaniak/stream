#ifndef _stream_buffer_h
#define _stream_buffer_h

/**
 * @file	stream_buffer.h
 * @author	en2
 * @date	17-08-2020
 * @brief	
 * @details	
**/

class Stream_buffer
{
    static constexpr auto _size = 1024;

public:
    char * address();

    char at(int position = 0);
    Stream_buffer & at(int position, char value);

    int size_actual();
    int size_max();
    int size_remaining();

    bool is_empty();
    bool is_full();

    Stream_buffer & clear();

protected:
    char _buffer[_size];

}; /* class: Stream_buffer */

#endif /* define: stream_buffer_h */