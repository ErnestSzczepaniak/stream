#include "stream_stack_channel.h"

namespace stream::stack
{

Channel::Channel(channel::Pointer & pointer) : _pointer(pointer)
{

}

Channel::~Channel()
{

}

void Channel::_input_data(void * data, int size)
{
    if (size + _pointer.position() < _pointer.span())
    {
        memcpy(_pointer, data, size);

        _pointer.move(size);
    }
}

char * Channel::_output_format(const char * delimiters)
{
    auto size = tools::string::get::size(_pointer, delimiters);

    if (size + _pointer.position() < _pointer.span())
    {
        char * temp = _pointer;

        _pointer.move(size + strlen(delimiters));

        return temp;
    }

    return nullptr;
}

void * Channel::_output_data(int size)
{
    if (size + _pointer.position() < _pointer.span())
    {
        void * temp = _pointer;

        _pointer.move(size);

        return temp;
    }

    return nullptr;
}

char * Channel::_find_format(char * string)
{   
    return tools::string::find::substring(_pointer, string, _pointer.span());
}

}; /* namespace: stream::stack */
