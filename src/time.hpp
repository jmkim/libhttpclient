#ifndef __LIBHTTPCLIENT_TIME_HPP
#define __LIBHTTPCLIENT_TIME_HPP    1

namespace libhttpclient
{
    class time
    {
    public:
        static std::time_t get_unixtime(void);
        static std::time_t strtounixtime(const std::string &time_formatted);
        static std::string unixtimetostr(
            const std::time_t unixtime = get_unixtime(),
            const std::string format = "%a, %d %b %Y %H:%M:%S %Z", /* RFC 822, updated by RFC 1123 */
            const int out_max_length = 300
        );
    };
}

#endif /* !__LIBHTTPCLIENT_TIME_HPP */
