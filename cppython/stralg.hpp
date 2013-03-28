#ifndef CPPYTHON_STRALG_HPP
#define CPPYTHON_STRALG_HPP


#include "detail/stralg_impl.hpp"


namespace cppython { namespace detail {

    /// @defgroup PythonLikeStringAlgorithm py-string-algorithm
    /// @{


    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// Algorithms
    ///
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /// @brief Return a copy of the string with only its first character chapitalized.
    /// @param[in] src
    /// @return std::string
    inline detail::capitalize_impl capitalize()
    {
        return detail::capitalize_impl();
    }


    /// @brief Return centered in a string of length width.
    /// @param[in] src
    /// @param[in] width length of width of centered string
    /// @return std::string
    inline detail::center_impl center(std::size_t width, const std::string& fillchar = std::string(" "))
    {
        return detail::center_impl(width, fillchar);
    }


    inline detail::count_impl count(const std::string& sub, int start = 0, int end = 0)
    {
        return detail::count_impl(sub, start, end);
    }


    inline detail::ljust_impl ljust(const size_t width, const std::string& fillchar = " ")
    {
        return detail::ljust_impl(width, fillchar);
    }


    inline detail::rjust_impl rjust(const size_t width, const std::string& fillchar = " ")
    {
        return detail::rjust_impl(width, fillchar);
    }



    inline detail::strip_impl strip(const std::string& chars = std::string())
    {
        return detail::strip_impl(chars);
    }



    inline detail::lstrip_impl lstrip(const std::string& chars = std::string())
    {
        return detail::lstrip_impl(chars);
    }


    inline detail::rstrip_impl rstrip(const std::string& chars = std::string())
    {
        return detail::rstrip_impl(chars);
    }


    inline detail::swapcase_impl swapcase()
    {
        return detail::swapcase_impl();
    }


    /// @brief Return a copy of the string converted to uppercase.
    inline detail::upper_impl upper()
    {
        return detail::upper_impl();
    }


    /// @brief Return a copy of the string converted to lowercase.
    inline detail::lower_impl lower()
    {
        return detail::lower_impl();
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// Find algorithms
    ///
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /// @brief Return the lowest index in the source string.
    /// Return -1 on failure
    inline detail::find_impl find(const std::string& sub, int start = 0, int end = 0)
    {
        return detail::find_impl(sub, start, end);
    }


    inline detail::index_impl index(const std::string& sub, int start = 0, int end = 0)
    {
        return detail::index_impl(sub, start, end);
    }


    /// @brief Return the highest index in the source string.
    /// Return -1 on failure.
    inline detail::rfind_impl rfind(const std::string& sub, int start = 0, int end = 0)
    {
        return detail::rfind_impl(sub, start, end);
    }


    inline detail::rindex_impl rindex(const std::string& sub, int start = 0, int end = 0)
    {
        return detail::rindex_impl(sub, start, end);
    }


    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// Erase and Replace algorithms
    ///
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /// @brief Return a copy of the string with all occurrences of substring old replaced by new.
    /// If the optional argument count is given, only the first count occurrences are replaced.
    inline detail::replace_impl replace(const std::string& old_str, const std::string& new_str, int count = 0)
    {
        return detail::replace_impl(old_str, new_str, count);
    }


    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// Join and Split algorithms
    ///
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /// @brief Return a string which is the concatenation of the strings in the sequence

    template <typename SequenceSequenceT>
    inline detail::join_impl<SequenceSequenceT> join(const SequenceSequenceT& seq)
    {
        return detail::join_impl<SequenceSequenceT>(seq);
    }


    template <typename SequenceSequenceT>
    inline detail::split_impl<SequenceSequenceT> split(const std::string& separator)
    {
        return detail::split_impl<SequenceSequenceT>(separator);
    }


    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// Predicates
    ///
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /// @brief
    inline detail::endswith_impl endswith(const std::string& suffix)
    {
        return detail::endswith_impl(suffix);
    }


    /// @brief Return true if all characters in the string are alphanumeric and
    /// there is at least one character, false otherwise.
    inline detail::isalnum_impl isalnum()
    {
        return detail::isalnum_impl();
    }



    /// @brief Return true if all characters in range src are alphabetic and there is at least
    /// onew character, false otherwise.
    inline detail::isalpha_impl isalpha()
    {
        return detail::isalpha_impl();
    }


    /// @brief Return true if characters in range src are digits.
    inline detail::isdigit_impl isdigit()
    {
        return detail::isdigit_impl();
    }


    inline detail::isupper_impl isupper()
    {
        return detail::isupper_impl();
    }


    inline detail::islower_impl islower()
    {
        return detail::islower_impl();
    }


    inline detail::isspace_impl isspace()
    {
        return detail::isspace_impl();
    }


    inline detail::istitle_impl istitle()
    {
        return detail::istitle_impl();
    }


    /// @brief
    inline detail::startswith_impl startswith(const std::string& prefix)
    {
        return detail::startswith_impl(prefix);
    }


    /// @brief Retrun the numeric string left filled with zeros in a string of length width.
    /// The original string is returned if width is less than boost::size(src).
    inline detail::zfill_impl zfill(const std::size_t width)
    {
        return detail::zfill_impl(width);
    }


    template <typename RangeT, typename Func> inline
    typename boost::result_of<Func(RangeT&)>::type
    operator|(RangeT& src, Func func)
    {
        return func(src);
    }


    template <typename RangeT, typename Func> inline
    typename boost::result_of<Func(const RangeT&)>::type
    operator|(const RangeT& src, Func func)
    {
        return func(src);
    }

    /// @}
}

using detail::capitalize;
using detail::center;
using detail::count;
using detail::ljust;
using detail::rjust;
using detail::strip;
using detail::lstrip;
using detail::rstrip;
using detail::swapcase;
using detail::upper;
using detail::lower;
using detail::find;
using detail::index;
using detail::rfind;
using detail::rindex;
using detail::replace;

using detail::endswith;
using detail::isalnum;
using detail::isalpha;
using detail::isdigit;
using detail::isupper;
using detail::islower;
using detail::isspace;
using detail::istitle;
using detail::startswith;
using detail::zfill;

using detail::join;
using detail::split;

} // namespace cppython
/*

#define CPPYTHON_STRALG_FUNCTION(FUNCTOR)                           \
template <typename RangeT>                                      \
typename boost::result_of<FUNCTOR(const RangeT&)>::type         \
operator|(const RangeT& src, FUNCTOR func)                      \
{                                                               \
    return func(src);                                           \
}

#define CPPYTHON_STRALG_FUNCTION_ARG(FUNCTOR, ARG1)                 \
template <typename RangeT, typename ARG1>                       \
typename boost::result_of<FUNCTOR<ARG1>(const RangeT&)>::type   \
operator|(const RangeT& src, FUNCTOR<ARG1> func)                \
{                                                               \
    return func(src);                                           \
}


CPPYTHON_STRALG_FUNCTION(detail::capitalize_impl)
CPPYTHON_STRALG_FUNCTION(detail::center_impl)
CPPYTHON_STRALG_FUNCTION(detail::count_impl)
CPPYTHON_STRALG_FUNCTION(detail::ljust_impl)
CPPYTHON_STRALG_FUNCTION(detail::rjust_impl)
CPPYTHON_STRALG_FUNCTION(detail::strip_impl)
CPPYTHON_STRALG_FUNCTION(detail::lstrip_impl)
CPPYTHON_STRALG_FUNCTION(detail::rstrip_impl)
CPPYTHON_STRALG_FUNCTION(detail::swapcase_impl)
CPPYTHON_STRALG_FUNCTION(detail::upper_impl)
CPPYTHON_STRALG_FUNCTION(detail::lower_impl)
CPPYTHON_STRALG_FUNCTION(detail::find_impl)
CPPYTHON_STRALG_FUNCTION(detail::index_impl)
CPPYTHON_STRALG_FUNCTION(detail::rfind_impl)
CPPYTHON_STRALG_FUNCTION(detail::rindex_impl)
CPPYTHON_STRALG_FUNCTION(detail::replace_impl)

CPPYTHON_STRALG_FUNCTION(detail::endswith_impl)
CPPYTHON_STRALG_FUNCTION(detail::isalnum_impl)
CPPYTHON_STRALG_FUNCTION(detail::isalpha_impl)
CPPYTHON_STRALG_FUNCTION(detail::isdigit_impl)
CPPYTHON_STRALG_FUNCTION(detail::isupper_impl)
CPPYTHON_STRALG_FUNCTION(detail::islower_impl)
CPPYTHON_STRALG_FUNCTION(detail::isspace_impl)
CPPYTHON_STRALG_FUNCTION(detail::istitle_impl)
CPPYTHON_STRALG_FUNCTION(detail::startswith_impl)
CPPYTHON_STRALG_FUNCTION(detail::zfill_impl)

CPPYTHON_STRALG_FUNCTION_ARG(detail::join_impl, SequenceSequenceT)
CPPYTHON_STRALG_FUNCTION_ARG(detail::split_impl, SequenceSequenceT)
*/

#endif
