#include "stream_stack_channel_parse.h"
#include <string>

namespace stream::stack::channel
{

Parse::Parse(char * start, char * stop) : pointer(start, stop), Channel(pointer)
{

}

Parse::~Parse()
{

}

bool Parse::is_present(const char * delimiters)
{
    return (tools::string::count::word(pointer, _option) > 0);
}

bool Parse::is_equal(char * value, const char * delimiters)
{
    auto * ptr = word();

    if (ptr != nullptr) return tools::string::compare::equality(ptr, value, delimiters);
    else return false;
}

bool Parse::starts_with(char * value)
{
    auto * ptr = word();
    
    for (int i = 0; i < tools::string::get::size(value); i++) if (ptr[i] != value[i]) return false;

    return true;
}

unsigned int Parse::decimal(const char * delimiters)
{
    auto * ptr = _find_format(_option);

    if (ptr != nullptr) return strtoul(ptr + tools::string::get::size(ptr, delimiters) + strlen(delimiters), nullptr, 10);
    else return {};
}

unsigned int Parse::hexadecimal(const char * delimiters)
{
    auto * ptr = _find_format(_option);

    if (ptr != nullptr) return strtoul(ptr + tools::string::get::size(ptr, delimiters) + strlen(delimiters), nullptr, 16);
    else return {};
}

float Parse::floating(const char * delimiters)
{
    auto * ptr = _find_format(_option);

    if (ptr != nullptr) return strtof(ptr + tools::string::get::size(ptr, delimiters) + strlen(delimiters), nullptr);
    else return {};
}

char Parse::character(const char * delimiters)
{
    auto * ptr = _find_format(_option);

    if (ptr != nullptr) return *(ptr + tools::string::get::size(ptr, delimiters) + strlen(delimiters));
    else return {};
}

bool Parse::boolean(const char * delimiters)
{
    return (decimal(delimiters) == 1);
}

char * Parse::word(const char * delimiters)
{
    auto * ptr = _find_format(_option);

    if (ptr != nullptr) return (ptr + tools::string::get::size(ptr, delimiters) + strlen(delimiters));
    else return {};
}

char * Parse::text(const char * delimiters)
{
    auto * ptr = _find_format(_option);

    if (ptr != nullptr) return (ptr + tools::string::get::size(ptr, delimiters) + strlen(delimiters));
    else return {};
}

Parse & Parse::option(char * option)
{
    _option = option;

    return *this;
}

}; /* namespace: stream::stack::channel */
