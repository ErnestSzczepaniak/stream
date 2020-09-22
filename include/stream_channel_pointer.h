#ifndef _stream_channel_pointer_h
#define _stream_channel_pointer_h

/**
 * @file	stream_channel_pointer.h
 * @author	en2
 * @date	22-09-2020
 * @brief	
 * @details	
**/

#include "tools_string.h"

namespace stream::channel
{

class Pointer
{
public:
    Pointer(char * start, int size);
    ~Pointer();

    Pointer & reset();

    int offset_end();
    bool is_aligned();
    Pointer & align_end();

    Pointer & position(int value);
    int position();

    operator char *();
    char operator*();

    Pointer & operator++(int);
    Pointer & operator--(int);
    
    Pointer & operator+=(int value);
    Pointer & operator-=(int value);

    Pointer & operator=(char * value);
    Pointer & operator=(Pointer & other);

    template<typename ...Args>
    Pointer & input(const char * format, Args ... args);
    char * output(const char * delimiters);

protected:
    Pointer & _move(int value);

private:
    char * _start;
    char * _current;
    int _size;  

}; /* class: Pointer */

template<typename ...Args>
Pointer & Pointer::input(const char * format, Args ... args)
{
    using namespace tools::string;

    int size;

    if (is_aligned() == false)
    {
        size = insert::preppend::format(_current, _size - (_current - _start), format, args...);
    }
    else
    {
        size = insert::append::format(_current, _size - (_current - _start), format, args...);
    }

    if (size > 0) _current += size;
    
    return *this;
}

}; /* namespace: stream::channel */

#endif /* define: stream_channel_pointer_h */