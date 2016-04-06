#ifndef __LIBHTTPCLIENT_ERRORT_HPP
#define __LIBHTTPCLIENT_ERRORT_HPP    1

namespace libhttpclient
{
    class error_t
    {
    private:
        /*
            Error message table
            <error_code, < {error_name, error_message} > >
        */
        std::map<int, std::array<std::string, 2> > table;

    public:
        error_t(void); /* Set error message table */

        std::string get(const int &code); /* Same as get_msg(int) */
        std::string get_name(const int &code);
        std::string get_msg(const int &code);
    };
}

#endif /* !__LIBHTTPCLIENT_ERRORT_HPP */
