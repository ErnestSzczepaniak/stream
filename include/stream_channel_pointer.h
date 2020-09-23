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
    Pointer(char * start, char * stop);
    ~Pointer();

    Pointer & start(char * value);
    char * start();

    Pointer & stop(char * value);
    char * stop();

    Pointer & current(char * value);
    char * current();

    Pointer & reset();
    Pointer & save();
    Pointer & restore();

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
    char * _stop;
    char * _current;

    char * _stash[3];

}; /* class: Pointer */

template<typename ...Args>
Pointer & Pointer::input(const char * format, Args ... args)
{
    int size;

    if (is_aligned()) size = tools::string::insert::append::format(_current, _stop - _current, format, args...);
    else size = tools::string::insert::preppend::format(_current, _stop - _current, format, args...);

    _move(size);
    
    return *this;
}

}; /* namespace: stream::channel */

#endif /* define: stream_channel_pointer_h */