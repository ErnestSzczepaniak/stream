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

    Pointer & position(int value);
    int position();

    Pointer & reset();

    operator char *();
    char operator*();

    Pointer & operator++(int);
    Pointer & operator--(int);
    
    Pointer & operator+=(int value);
    Pointer & operator-=(int value);

    Pointer & operator=(char * value);
    Pointer & operator=(Pointer & other);

protected:
    Pointer & _move(int value);

private:
    char * _start;
    char * _current;
    int _size;

}; /* class: Stream_pointer */

template<typename ...Args>
static inline void pointer_input(Pointer & pointer, const char * format, Args ... args)
{
    // using namespace tools::string;

    // int size;

    // if (*pointer != 0)
    // {
    //     size = insert::preppend::format(pointer.current(), pointer.size_stop(), format, args...);
    // }
    // else
    // {
    //     size = insert::append::format(pointer.start(), pointer.size_stop(), format, args...);
    // }

    // if (size > 0) pointer.move(size);
}

static inline char * pointer_output(Pointer & pointer, int word, const char * delimiters)
{
    // using namespace tools::string;

    // auto * ptr = get::word(pointer.current(), word, delimiters);

    // if (ptr == nullptr) return nullptr;

    // auto size_word = get::size(ptr, " ");

    // pointer.move(size_word + get::size((char *) delimiters));

    // return ptr;
}

}; /* namespace: stream */


#endif /* define: stream_pointer_h */