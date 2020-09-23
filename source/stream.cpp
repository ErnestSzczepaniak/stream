#include "stream.h"

Stream::Stream()
{
    // input.reset();
    // output.reset();
    // error.reset();
}

Stream::~Stream()
{

}

Stream & Stream::reset()
{
    // input.reset();
    // output.reset();
    // error.reset();

    return *this;
}

Stream & Stream::flush()
{
    // input = output;
    // output.reset();

    return *this;
}
