#ifndef _stream_pointer_h
#define _stream_pointer_h

/**
 * @file	stream_pointer.h
 * @author	en2
 * @date	17-08-2020
 * @brief	
 * @details	
**/

class Stream_pointer
{
public:
    char * initial();
    Stream_pointer & initial(char * value);

    char * current();
    Stream_pointer & current(char * value);

    int position();
    Stream_pointer & position(int value);

    Stream_pointer & reset();
    Stream_pointer & move(int value);

private:
    char * _initial = nullptr;
    char * _current = nullptr;

}; /* class: Stream_pointer */

#endif /* define: stream_pointer_h */