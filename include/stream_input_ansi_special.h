#ifndef _stream_input_ansi_special_h
#define _stream_input_ansi_special_h

/**
 * @file	stream_input_ansi_special.h
 * @author	en2
 * @date	08-09-2020
 * @brief	
 * @details	
**/

#include "stream_pointer.h"

namespace stream::input::ansi
{

class Special
{
public:
    Special(Pointer & pointer);
    ~Special();

    Special & a();
    Special & b();
    Special & r();
    Special & n();
    Special & t();
    Special & v();
    Special & f();

private:
    Pointer & _pointer;

}; /* class: Special */

}; /* namespace: stream::input::ansi */


#endif /* define: stream_input_ansi_special_h */