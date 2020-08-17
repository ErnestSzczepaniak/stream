#ifndef _stream_generic_h
#define _stream_generic_h

/**
 * @file	stream_generic.h
 * @author	en2
 * @date	17-08-2020
 * @brief	
 * @details	
**/

#include "stream_pointer.h"

class Stream_generic
{
    static constexpr auto _size = 1024;

public:
    Stream_generic();

    char at(int position = 0);
    Stream_generic & at(int position, char value);

    int size_actual();
    int size_max();
    int size_remaining();

    bool is_empty();
    bool is_full();

    Stream_generic & clear();

    Stream_pointer pointer;

protected:
    char _buffer[_size];

}; /* class: Stream_generic */

#endif /* define: stream_generic_h */