#ifndef _stream_generic_h
#define _stream_generic_h

/**
 * @file	stream_generic.h
 * @author	en2
 * @date	21-07-2020
 * @brief	
 * @details	
**/

class Stream_generic
{
public:
    Stream_generic(char * buffer_front, char * buffer_back, int size);

    Stream_generic & reset();

protected:
    char * _pointer_front = nullptr;
    char * _pointer_back = nullptr;
    char * _buffer_front = nullptr;
    char * _buffer_back = nullptr;
    int _size = 0;

private:


}; /* class: Stream_generic */


#endif /* define: stream_generic_h */