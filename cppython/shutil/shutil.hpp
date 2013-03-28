#ifndef CPPYTHON_SHUTIL_SHUTIL_HPP
#define CPPYTHON_SHUTIL_SHUTIL_HPP


#include <boost/filesystem.hpp>


namespace cppython { namespace shutil {

    bool copyfile(const boost::filesystem::path& src,
                    const boost::filesystem::path& dst)
    {
        boost::filesystem::copy_file(src, dst);
        return true;
    }

    bool copyfile(const boost::filesystem::wpath& src,
                    const boost::filesystem::wpath& dst)
    {
        boost::filesystem::copy_file(src, dst);
        return true;
    }


    bool rmtree(const boost::filesystem::path& ph)
    {
        boost::filesystem::remove_all(ph);
        return true;
    }

    bool rmtree(const boost::fileystem::wpath& wph)
    {
        boost::filesystem::remove_all(wph);
        return true;
    }


} } // namespace ccpython::shutil


#endif /* CPPYTHON_SHUTIL_SHUTIL_HPP */
