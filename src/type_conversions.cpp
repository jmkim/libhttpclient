#include <string>

#include "type_conversions.hpp"

std::string libhttpclient::type_conversions::carrtostr(const char carr[])
{
    std::string out;
    for(char c : carr)
    {
        out.push_back(c);
        if(c == '\0') break; /* Stop copying when the string ends */
    }

    return out;
}
