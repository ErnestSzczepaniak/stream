#include "stream.h"

Stream::Stream()
{

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

Stream & Stream::clear()
{
    command.clear();
    input.clear();
    output.clear();
    error.clear();

    return *this;
}

Stream & Stream::flush()
{
    input = output;
    output.clear();

    return *this;
}
