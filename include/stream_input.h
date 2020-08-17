#ifndef _stream_input_h
#define _stream_input_h

/**
 * @file	stream_input.h
 * @author	en2
 * @date	17-08-2020
 * @brief	
 * @details	
**/

#include "stream_buffer_pointer.h"

class Stream_input
{
public:
    Stream_input(Stream_buffer & buffer);
    
    template<typename ...Args>
    Stream_input & format(const char * format, Args ... args);

    //Stream_buffer_pointer pointer;

}; /* class: Stream_input */

template<typename ...Args>
Stream_input & Stream_input::format(const char * format, Args ... args)
{
    // auto size = snprintf(pointer.get(), _size - pointer.position(), format, args...);

    // pointer.move(size);

    // return *this;
}

#endif /* define: stream_input_h */