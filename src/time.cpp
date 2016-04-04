#include <string>
#include <ctime>

#include "time.hpp"

std::time_t libhttpclient::time::get_unixtime(void)
{
    return std::time(NULL);
}

std::time_t libhttpclient::time::strtounixtime(const std::string &time_formatted)
{
    const std::string formats[] = /* List of parsing format */
    {
        "%a, %d %b %Y %H:%M:%S %Z", /* Thu, 03 Mar 2016 20:24:02 GMT        RFC 822, updated by RFC 1123 */
        "%A, %d-%b-%y %H:%M:%S %Z", /* Thursday, 03-Mar-16 20:24:02 GMT     RFC 850, obsoleted by RFC 1036 */
        "%a %b %e %H:%M:%S %Y",     /* Thu Mar  3 20:24:02 2016             ANSI C's asctime() format */
        "%a, %d-%b-%Y %H:%M:%S %Z"  /* Thu, 03-Mar-2016 20:24:02 GMT        Set-Cookie expires format in PWS/8.1.20.25 */
    };

    for(std::string format : formats) /* Parse time_formatted with formats[] */
    {
        struct std::tm unixtime;

        if(strptime(time_formatted.c_str(), format.c_str(), &unixtime) != NULL)
            return mktime(&unixtime) + unixtime.tm_gmtoff; /* .tm_gmtoff to do not apply the localtime offset */
    }

    return 0; /* Return the 0 Unix time when failed parsing */
}

std::string libhttpclient::time::unixtimetostr(const std::time_t unixtime, const std::string format, const int out_max_length)
{
    char out[out_max_length] = {0, };
    std::strftime(out, sizeof(out), format.c_str(), std::gmtime(&unixtime));

    return libhttpclient::type_conversions::carrtostr(out);
}
