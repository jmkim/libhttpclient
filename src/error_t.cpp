#include <map>
#include <array>

#include "error_t.hpp"
#include <errno.h> /* Include the error codes in C standard library */

std::string libhttpclient::error_t::get(const int &code) { return libhttpclient::error_t::get_msg(code); }

std::string libhttpclient::error_t::get_name(const int &code)
{
    auto result = table.find(code);
    if(result != table.end()) return result->second[0]; /* Found */

    return std::to_string(code); /* Not found - return the code */
}

std::string libhttpclient::error_t::get_msg(const int &code)
{
    auto result = table.find(code);
    if(result != table.end()) return result->second[1]; /* Found */

    return "Unknown error (code " + std::to_string(code) + ")"; /* Not found - return this string */
}

libhttpclient::error_t::error_t(void)
{
#define ENTRY(value, name, msg)     error_t::table.insert(std::make_pair(value, std::array<std::string, 2>({ std::string(name), std::string(msg) })));

    /* Error code 'NULL' */
    {
        ENTRY(0, "", "");
#if NULL != 0
        ENTRY(NULL, "NULL", ""); /* NULL != 0 */
#endif
    }

    /* The entry section of error message table */
    {
        /* TODO: Add the error message table here */
    }

#undef  ENTRY
}
