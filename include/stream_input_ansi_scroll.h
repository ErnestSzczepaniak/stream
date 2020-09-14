#ifndef _stream_input_ansi_scroll_h
#define _stream_input_ansi_scroll_h

/**
 * @file	stream_input_ansi_scroll.h
 * @author	en2
 * @date	08-09-2020
 * @brief	
 * @details	
**/

#include "stream_pointer.h"

namespace stream::input::ansi
{

class Scroll
{
public:
    Scroll(Pointer & pointer);
    ~Scroll();

    Scroll & up();
    Scroll & down();

private:
    Pointer & _pointer;

}; /* class: Scroll */

}; /* namespace: stream::input::ansi */

#endif /* define: stream_input_ansi_scroll_h */