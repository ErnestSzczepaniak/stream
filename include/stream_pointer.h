#ifndef _stream_pointer_h
#define _stream_pointer_h

/**
 * @file	stream_pointer.h
 * @author	en2
 * @date	17-08-2020
 * @brief	
 * @details	
**/


/*

a b c d e f g \0 \0 \0 \0
.     .     .
|_____|_____|______ start
      |_____|______ current
            |______ end
*/

#include "tools_string.h"

namespace stream
{

class Pointer
{
public:
    Pointer(char * start, int size);
    ~Pointer();

    Pointer & reset();

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
    static void input(Pointer & pointer, const char * format, Args ... args);
    static char * output(Pointer & pointer, int word, const char * delimiters);

protected:
    Pointer & _move(int value);

private:
    char * _start;
    char * _current;
    int _size;

}; /* class: Stream_pointer */

template<typename ...Args>
void Pointer::input(Pointer & pointer, const char * format, Args ... args)
{
    using namespace tools::string;

    int size;

    if (*pointer != 0)
    {
        size = insert::preppend::format(pointer, pointer._size - (pointer - pointer._start), format, args...);
    }
    else
    {
        size = insert::append::format(pointer, pointer._size - (pointer - pointer._start), format, args...);
    }

    if (size > 0) pointer += size;
}

}; /* namespace: stream */


#endif /* define: stream_pointer_h */