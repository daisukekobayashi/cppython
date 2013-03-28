#ifndef CPPYTHON_EXCEPTION_HPP
#define CPPYTHON_EXCEPTION_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <boost/exception/all.hpp>


namespace cppython { namespace exception {

    typedef boost::error_info<struct tag_errmsg, std::string> errmsg_info;

    class OSError : public boost::exception, public std::exception { };
    class TypeError : public boost::exception, public std::exception { };
    class ValueError : public boost::exception, public std::exception { };


} } // namespace cppython::exception

#endif
