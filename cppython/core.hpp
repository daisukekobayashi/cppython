#ifndef CPPYTHON_CORE_HPP
#define CPPYTHON_CORE_HPP

#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
#include <boost/cstdint.hpp>
#include <boost/range.hpp>


namespace cppython {

    namespace detail {

        struct gen_seq {
            gen_seq(const boost::int64_t start) : start_(start - 1) { }
            boost::int64_t operator()() { return ++start_; }
            boost::int64_t start_;
        };

        /// @brief functor that generate arithmetic sequence.
        template <typename T>
        struct gen_arseq {
            gen_arseq(const T start, const T step): start_(start), step_(step) { }
            T operator()()
            {
                T temp = start_;
                start_ += step_;
                return temp;
            }
            T start_;
            T step_;
        };

        /// @brief Return number of items
        template <typename T>
        boost::uint64_t get_len_of_range(T lo, T hi, T step)
        {
            return boost::uint64_t(((hi - lo) / step) + 1.5);
        }

    } // namespace detail

    template <typename RangeT>
    inline typename boost::range_size<RangeT>::type len(RangeT& src)
    {
        return boost::size(src);
    }

    template <typename RangeT>
    inline typename boost::range_reference<RangeT>::type
    slice(RangeT& src, int nth)
    {
        return boost::make_iterator_range<RangeT>(src)[nth];
    }

    template <typename RangeT>
    boost::iterator_range<typename boost::range_iterator<RangeT>::type>
    slice(RangeT& src, int start, int stop)
    {
        using namespace boost;
        typedef typename range_iterator<RangeT>::type iter_type;

        if (start < 0) start = size(src) + start;
        if (stop > 0) stop = stop - size(src);
        return make_iterator_range(src, start, stop);
    }


    template <typename SequenceSequenceT>
    SequenceSequenceT& range(SequenceSequenceT& result, boost::uint64_t stop)
    {
        SequenceSequenceT temp(stop);
        std::generate(temp.begin(), temp.end(), detail::gen_seq(0));
        result.swap(temp);
        return result;
    }

    template <typename SequenceSequenceT>
    SequenceSequenceT& range(SequenceSequenceT& result,
                             const typename SequenceSequenceT::value_type start,
                             const typename SequenceSequenceT::value_type stop,
                             const typename SequenceSequenceT::value_type step = 1)
    {
        typedef typename SequenceSequenceT::value_type result_value_t;
        boost::uint64_t n = detail::get_len_of_range(start, stop, step);
        SequenceSequenceT temp(n);
        std::generate(temp.begin(), temp.end(), detail::gen_arseq<result_value_t>(start, step));
        result.swap(temp);
        return result;
    }


    /// @brief print elements in range.
    template <typename RangeT>
    bool print(const RangeT& src, std::ostream& ost = std::cout, char* delimiter = ", ")
    {
        using namespace boost;

        typedef typename boost::range_const_iterator<RangeT>::type iter_type;
        boost::iterator_range<iter_type> pos = slice(src, 0, -1);

        ost << '[';
        std::copy(const_begin(pos), const_end(pos),
                std::ostream_iterator< typename range_value<RangeT>::type >(ost, delimiter));
        ost << *const_end(pos) << ']' << std::endl;

        return true;
    }


} // namespace cppython

#endif
