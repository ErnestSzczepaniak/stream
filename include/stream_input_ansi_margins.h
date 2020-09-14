#ifndef _stream_input_ansi_margins_h
#define _stream_input_ansi_margins_h

/**
 * @file	stream_input_ansi_margins.h
 * @author	en2
 * @date	08-09-2020
 * @brief	
 * @details	
**/

#include "stream_pointer.h"

namespace stream::input::ansi
{

class Margins
{
public:
    Margins(Pointer & pointer);
    ~Margins();

    Margins & horizontal(int from, int to);
    Margins & vertical(int from, int to);     

private:
    Pointer & _pointer;

}; /* class: Margins */

}; /* namespace: stream::input::ansi */

#endif /* define: stream_input_ansi_margins_h */