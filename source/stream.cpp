#include "stream.h"

Stream::Stream()
{
    command.reset();
    input.reset();
    output.reset();
    error.reset();
}

Stream::~Stream()
{

}

Stream & Stream::reset()
{
    command.reset();
    input.reset();
    output.reset();
    error.reset();

    return *this;
}

Stream & Stream::flush()
{
    input = output;
    output.reset();

    return *this;
}
