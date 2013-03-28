#ifndef CPPYTHON_DETAIL_STRALG_IMPL_HPP
#define CPPYTHON_DETAIL_STRALG_IMPL_HPP


#include "../core.hpp"
#include "../exception.hpp"
#include <cstddef>
#include <cstdlib>
#include <string>
#include <boost/range.hpp>
#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/utility/result_of.hpp>



namespace cppython { namespace detail {

    // Forward declaration
    struct lower_impl;

    struct capitalize_impl {
        typedef std::string result_type;
        template<typename RangeT>
        result_type operator()(const RangeT& src) {
            result_type temp(lower_impl()(src));
            std::toupper(temp[0], std::locale());
            return temp;
        }
    };


    struct center_impl {
        typedef std::string result_type;
        center_impl(std::size_t width, const std::string& fillchar) :
            width_(width), fillchar_(fillchar) {
        }

        template<typename RangeT>
        std::string operator()(const RangeT& src) {
            try {
                if (fillchar_.size() > 1) {
                    throw exception::TypeError();
                }
                std::string temp(src);
                if (temp.size() >= width_)
                    return temp;
                else {
                    std::size_t space = width_ - temp.size();
                    return std::string(static_cast<size_t> (space / 2),
                            fillchar_[0]) + temp + std::string(
                            static_cast<size_t> (space - space / 2), fillchar_[0]);
                }
            } catch (boost::exception& e) {
                e << exception::errmsg_info(
                        "center() argument 3 must be char, not string");
                std::cout << boost::diagnostic_information(e);
            }
        }
    private:
        std::size_t width_;
        std::string fillchar_;
    };


    struct count_impl {
        typedef std::size_t result_type;
        count_impl(const std::string& sub, int start, int end) :
            sub_(sub), start_(start), end_(end) {
        }

        template<typename RangeT>
        std::size_t operator()(const RangeT& src) {
    typedef     typename boost::range_iterator<RangeT>::type iter_type;
            std::vector< typename boost::iterator_range<iter_type> > temp;
            boost::algorithm::find_all(temp, src, sub_);
            return temp.size();
        }
    private:
        std::string sub_;
        int start_;
        int end_;
    };


    struct ljust_impl {
        typedef std::string result_type;
        ljust_impl(const size_t width, const std::string& fillchar)
        : width_(width), fillchar_(fillchar) {}

        template <typename RangeT>
        std::string operator()(const RangeT& src)
        {
            try {
                if (fillchar_.size() > 1) {
                    throw exception::TypeError();
                }
                std::string temp(src);
                if (temp.size() >= width_)
                return temp;
                else {
                    size_t space = width_ - temp.size();
                    return temp + std::string(static_cast<size_t>(space), fillchar_[0]);
                }
            } catch (boost::exception& e) {
                e << exception::errmsg_info("center() argument 3 must be char, not string");
                //std::cout << *boost::get_error_info<exception::errmsg_info>(e) << std::endl;
                std::cout << boost::diagnostic_information(e);
            }
            return src;
        }
    private:
        std::size_t width_;
        std::string fillchar_;
    };


    struct rjust_impl {
        typedef std::string result_type;
        rjust_impl(const size_t width, const std::string& fillchar)
        : width_(width), fillchar_(fillchar) {}

        template <typename RangeT>
        std::string operator()(const RangeT& src)
        {
            try {
                if (fillchar_.size() > 1) {
                    throw exception::TypeError();
                }
                std::string temp(src);
                if (temp.size() >= width_)
                return temp;
                else {
                    size_t space = width_ - temp.size();
                    return std::string(static_cast<size_t>(space), fillchar_[0]) + temp;
                }
            } catch (boost::exception& e) {
                e << exception::errmsg_info("center() argument 3 must be char, not string");
                //std::cout << *boost::get_error_info<exception::errmsg_info>(e) << std::endl;
                std::cout << boost::diagnostic_information(e);
            }
            return src;
        }
    private:
        std::size_t width_;
        std::string fillchar_;
    };


    struct strip_impl {
        typedef std::string result_type;
        strip_impl(const std::string& chars) : chars_(chars) {}

        template <typename RangeT>
        std::string operator()(const RangeT& src)
        {
            namespace alg = boost::algorithm;

            std::string temp(boost::begin(src), boost::end(src));
            return chars_.size() == 0 ? alg::trim_copy(temp)
            : alg::trim_copy_if(temp, alg::is_any_of(chars_));
        }
    private:
        std::string chars_;
    };


    struct lstrip_impl {
        typedef std::string result_type;
        lstrip_impl(const std::string& chars) : chars_(chars) {}

        template <typename RangeT>
        std::string operator()(const RangeT& src)
        {
            namespace alg = boost::algorithm;

            std::string temp(boost::begin(src), boost::end(src));
            return chars_.size() == 0 ? alg::trim_left_copy(temp)
            : alg::trim_left_copy_if(temp, alg::is_any_of(chars_));
        }
    private:
        std::string chars_;
    };


    struct rstrip_impl {
        typedef std::string result_type;
        rstrip_impl(const std::string& chars) : chars_(chars) {}

        template <typename RangeT>
        std::string operator()(const RangeT& src)
        {
            namespace alg = boost::algorithm;

            std::string temp(boost::begin(src), boost::end(src));
            return chars_.size() == 0 ? alg::trim_right_copy(temp)
            : alg::trim_right_copy_if(temp, alg::is_any_of(chars_));
        }
    private:
        std::string chars_;
    };


    struct swapcase_impl {
        typedef std::string result_type;
        template <typename RangeT>
        std::string operator()(const RangeT& src)
        {
            std::string temp(boost::begin(src), boost::end(src));
            std::string ls(temp);
            std::transform(ls.begin(), ls.end(), ls.begin(), ::toupper);

            for (std::string::size_type i = 0; i < temp.size(); i++) {
                if (ls[i] == temp[i]) ls[i] = std::tolower(ls[i], std::locale());
            }
            return ls;
        }
    };


    struct upper_impl {
        typedef std::string result_type;
        template <typename RangeT>
        std::string operator()(const RangeT& src)
        {
            std::string temp(boost::begin(src), boost::end(src));
            return boost::algorithm::to_upper_copy(temp);
        }
    };


    struct lower_impl {
        typedef std::string result_type;
        template <typename RangeT>
        std::string operator()(const RangeT& src)
        {
            std::string temp(boost::begin(src), boost::end(src));
            return boost::algorithm::to_lower_copy(temp);
        }
    };


    struct find_impl {
        typedef std::string::size_type result_type;
        find_impl(const std::string sub, int start, int end)
        : sub_(sub), start_(start), end_(end) {}
        template <typename Range1T>
        result_type operator()(Range1T& src)
        {
            typedef typename boost::range_iterator<Range1T>::type iter_type;
            typedef typename boost::iterator_range<iter_type> irange_t;

            irange_t temp = slice(src, start_, end_);
            irange_t rng = boost::algorithm::find_first(temp, sub_);
            if (rng)
            return rng.begin() - boost::begin(src);
            else
            return -1;
        }

    private:
        std::string sub_;
        int start_;
        int end_;
    };


    struct index_impl {
        typedef std::string::size_type result_type;
        index_impl(const std::string sub, int start, int end)
        : sub_(sub), start_(start), end_(end) {}
        template <typename Range1T>
        result_type operator()(Range1T& src)
        {
            typedef typename boost::range_iterator<Range1T>::type iter_type;
            typedef typename boost::iterator_range<iter_type> irange_t;

            irange_t temp = slice(src, start_, end_);
            irange_t rng = boost::algorithm::find_first(temp, sub_);

            try {
                if (rng)
                return rng.begin() - boost::begin(src);
                else
                throw exception::ValueError();
            } catch (boost::exception& e) {
                e << exception::errmsg_info("substring not found");
                //std::cout << *boost::get_error_info<exception::errmsg_info>(e) << std::endl;
                std::cout << boost::diagnostic_information(e);
            }
        }

    private:
        std::string sub_;
        int start_;
        int end_;
    };


    struct rfind_impl {
        typedef std::string::size_type result_type;
        rfind_impl(const std::string sub, int start, int end)
        : sub_(sub), start_(start), end_(end) {}
        template <typename Range1T>
        result_type operator()(Range1T& src)
        {
            typedef typename boost::range_iterator<Range1T>::type iter_type;
            typedef typename boost::iterator_range<iter_type> irange_t;

            irange_t temp = slice(src, start_, end_);
            irange_t rng = boost::algorithm::find_last(temp, sub_);
            if (rng)
            return rng.begin() - boost::begin(src);
            else
            return -1;
        }

    private:
        std::string sub_;
        int start_;
        int end_;
    };


    struct rindex_impl {
        typedef std::string::size_type result_type;
        rindex_impl(const std::string sub, int start, int end)
        : sub_(sub), start_(start), end_(end) {}
        template <typename Range1T>
        result_type operator()(Range1T& src)
        {
            typedef typename boost::range_iterator<Range1T>::type iter_type;
            typedef typename boost::iterator_range<iter_type> irange_t;

            irange_t temp = slice(src, start_, end_);
            irange_t rng = boost::algorithm::find_last(temp, sub_);

            try {
                if (rng)
                return rng.begin() - boost::begin(src);
                else
                throw exception::ValueError();
            } catch (boost::exception& e) {
                e << exception::errmsg_info("substring not found");
                //std::cout << *boost::get_error_info<exception::errmsg_info>(e) << std::endl;
                std::cout << boost::diagnostic_information(e);
            }
        }

    private:
        std::string sub_;
        int start_;
        int end_;
    };

    struct replace_impl {
        typedef std::string result_type;
        replace_impl(const std::string& old_str, const std::string& new_str, int count)
        : old_str_(old_str), new_str_(new_str), count_(count) {}
        template <typename RangeT>
        result_type operator()(const RangeT& src)
        {
            namespace alg = boost::algorithm;

            std::string temp(boost::begin(src), boost::end(src));
            return count_ == 0 ? alg::replace_all_copy(temp, old_str_, new_str_)
            : alg::replace_nth_copy(temp, old_str_, count_, new_str_);
        }

    private:
        std::string old_str_;
        std::string new_str_;
        int count_;
    };


    template <typename SequenceSequenceT>
    struct join_impl {
        typedef typename boost::range_value<SequenceSequenceT>::type result_type;
        join_impl(const SequenceSequenceT& seq) : seq_(seq) {}
        template <typename RangeT>
        result_type operator()(const RangeT& src)
        {
            return boost::algorithm::join(seq_, src);
        }
    private:
        SequenceSequenceT seq_;
    };

    template <typename SequenceSeqenceT = std::vector<std::string> >
    struct split_impl {
        typedef SequenceSeqenceT result_type;
        split_impl(const std::string& separator) : separator_(separator) {}
        template <typename RangeT>
        result_type operator()(const RangeT& src)
        {
            result_type temp;
            boost::algorithm::split(temp, src, boost::algorithm::is_any_of(separator_));
            return temp;
        }
    private:
        std::string separator_;
    };


    struct endswith_impl {
        typedef bool result_type;
        endswith_impl(const std::string& suffix) : suffix_(suffix) { }
        template <typename RangeT>
        result_type operator()(const RangeT& src)
        {
            return boost::algorithm::ends_with(src, suffix_);
        }
    private:
        std::string suffix_;
    };


    struct isalnum_impl {
        typedef bool result_type;
        template <typename RangeT>
        result_type operator()(const RangeT& src)
        {
            namespace alg = boost::algorithm;
            if (!boost::empty(src) && alg::all(src, alg::is_alnum()))
                return true;
            else
                return false;
        }
    };


    struct isalpha_impl {
        typedef bool result_type;
        template <typename RangeT>
        result_type operator()(const RangeT& src)
        {
            namespace alg = boost::algorithm;
            if (!boost::empty(src) && alg::all(src, alg::is_alpha()))
                return true;
            else
                return false;
        }
    };


    struct isdigit_impl {
        typedef bool result_type;
        template <typename RangeT>
        result_type operator()(const RangeT& src)
        {
            namespace alg = boost::algorithm;
            if (!boost::empty(src) && alg::all(src, alg::is_digit()))
                return true;
            else
                return false;
        }
    };


    struct isupper_impl {
        typedef bool result_type;
        template <typename RangeT>
        result_type operator()(const RangeT& src)
        {
            namespace alg = boost::algorithm;
            if (!boost::empty(src) && alg::all(src, alg::is_upper()))
                return true;
            else
                return false;
        }
    };


    struct islower_impl {
        typedef bool result_type;
        template <typename RangeT>
        result_type operator()(const RangeT& src)
        {
            namespace alg = boost::algorithm;
            if (!boost::empty(src) && alg::all(src, alg::is_lower()))
                return true;
            else
                return false;
        }
    };


    struct isspace_impl {
        typedef bool result_type;
        template <typename RangeT>
        result_type operator()(const RangeT& src)
        {
            namespace alg = boost::algorithm;
            if (!boost::empty(src) && alg::all(src, alg::is_space()))
                return true;
            else
                return false;
        }
    };


    struct istitle_impl {
        typedef bool result_type;
        template <typename RangeT>
        result_type operator()(const RangeT& src)
        {
            namespace alg = boost::algorithm;
            if (!boost::empty(src) && alg::all(alg::find_head(src, 1), alg::is_upper()))
                return true;
            else
                return false;
        }
    };


    struct startswith_impl {
        typedef bool result_type;
        startswith_impl(const std::string& prefix) : prefix_(prefix) { }
        template <typename RangeT>
        result_type operator()(const RangeT& src)
        {
            return boost::algorithm::starts_with(src, prefix_);
        }
    private:
        std::string prefix_;
    };

    
    struct zfill_impl {
        typedef std::string result_type;
        zfill_impl(const std::size_t width) : width_(width) { }
        template <typename RangeT>
        result_type operator()(const RangeT& src)
        {
            result_type temp(boost::begin(src), boost::end(src));
            if (temp.size() >= width_) {
                return temp;
            } else {
                std::string fmt = std::string("%0") +
                    boost::lexical_cast<std::string>(width_) + "d";
                return boost::io::str(boost::format(fmt) % std::atoi(temp.c_str()));
            }
        }
    private:
        std::size_t width_;
    };

} } // namespace cppython::detail


#endif /* CPPYTHON_DETAIL_STRALG_FUNCTOR_HPP */
