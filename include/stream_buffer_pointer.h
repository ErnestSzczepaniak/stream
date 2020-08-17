#ifndef _stream_buffer_pointer_h
#define _stream_buffer_pointer_h

/**
 * @file	stream_buffer_pointer.h
 * @author	en2
 * @date	17-08-2020
 * @brief	
 * @details	
**/

class Stream_buffer_pointer
{
public:
    Stream_buffer_pointer(char * pointer);

    char * get();
    Stream_buffer_pointer & set(char * value);

    int position();
    Stream_buffer_pointer & position(int value);

    Stream_buffer_pointer & reset();
    Stream_buffer_pointer & move(int value);

private:
    char * _initial;
    char * _current;

}; /* class: Stream_buffer_pointer */

#endif /* define: stream_buffer_pointer_h */