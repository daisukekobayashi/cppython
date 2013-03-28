#ifndef CPPYTHON_OS_OS_HPP
#define CPPYTHON_OS_OS_HPP

#define BOOST_FILESYSTEM_VERSION 2

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <iterator>
#include <algorithm>
#include <boost/range.hpp>
#include <boost/filesystem.hpp>
#include <boost/concept_check.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>


namespace cppython { namespace os {


    inline std::string abspath(const boost::filesystem::path& ph)
    {
        namespace fs = boost::filesystem;
        return fs::complete(ph, fs::current_path()).string();
    }
/*
    inline std::wstring abspath(const boost::filesystem::wpath& wph)
    {
        namespace fs = boost::filesystem;
        return fs::complete(wph, fs::wpath(fs::current_path())).string();
    }
*/

    /// @brief Returns current directory
    inline std::string getcwd()
    {
        return boost::filesystem::current_path().string();
    }

    inline std::string getcwdu()
    {
        return boost::filesystem::current_path().external_file_string();
    }


    inline std::string getenv(const std::string& src)
    {
        return std::getenv(src.c_str());
    }

    inline boost::uintmax_t getsize(const boost::filesystem::path& ph)
    {
        return boost::filesystem::file_size(ph);
    }

    inline boost::uintmax_t getsize(const boost::filesystem::wpath& wph)
    {
        return boost::filesystem::file_size(wph);
    }

    /// \brief create directory
    inline bool mkdir(const boost::filesystem::path& ph)
    {
        return boost::filesystem::create_directory(ph);
    }

    inline bool mkdir(const boost::filesystem::wpath& wph)
    {
        return boost::filesystem::create_directory(wph);
    }

    /// \brief create directories
    inline bool makedirs(const boost::filesystem::path& ph)
    {
        return boost::filesystem::create_directories(ph);
    }

    inline bool makedirs(const boost::filesystem::wpath& wph)
    {
        return boost::filesystem::create_directories(wph);
    }


    inline bool remove(const boost::filesystem::path& ph)
    {
        try {
            if (!boost::filesystem::is_directory(ph)) {
                boost::filesystem::remove(ph);
                return true;
            } else {
                throw exception::OSError();
            }
        } catch (boost::exception& e) {
            std::string msg("[Errno 21] Is a directory: ");
            msg += "'" + ph.string() + "'";
            e << exception::errmsg_info(msg);
            std::cout << boost::diagnostic_information(e);
        }
        return false;
    }

    inline bool remove(const boost::filesystem::wpath& wph)
    {
        boost::filesystem::remove(wph);
        return true;
    }


    inline bool removedirs(const boost::filesystem::path& ph)
    {
        boost::filesystem::remove_all(ph);
        return true;
    }

    inline bool removedirs(const boost::filesystem::wpath& wph)
    {
        boost::filesystem::remove_all(wph);
        return true;
    }

    /// \brief rename file or directory
    inline bool rename(const boost::filesystem::path& src,
                 const boost::filesystem::path& dst)
    {
        boost::filesystem::rename(src, dst);
        return true;
    }

    inline bool rename(const boost::filesystem::wpath& src, const boost::filesystem::wpath& dst)
    {
        boost::filesystem::rename(src, dst);
        return true;
    }


    inline bool rmdir(const boost::filesystem::path& ph)
    {
        if (boost::filesystem::is_directory(ph)) {
            boost::filesystem::remove(ph);
            return true;
        }
        return false;
    }

    inline bool rmdir(const boost::filesystem::wpath& wph)
    {
        if (boost::filesystem::is_directory(wph)) {
            boost::filesystem::remove(wph);
            return true;
        }
        return false;
    }


    inline bool link(const boost::filesystem::path& src,
               const boost::filesystem::path& dst)
    {
        boost::filesystem::create_hard_link(src, dst);
        return true;
    }

    inline bool link(const boost::filesystem::wpath& src,
               const boost::filesystem::wpath& dst)
    {
        boost::filesystem::create_hard_link(src, dst);
        return true;
    }

    /// \brief Returns sequence of file and directory in argument path.
    template <typename Sequence> inline
    bool listdir(Sequence& seq, const boost::filesystem::path& ph)
    {
        namespace fs = boost::filesystem;
        boost::function_requires< boost::BackInsertionSequenceConcept<Sequence> >();

        fs::directory_iterator end_it;
        for (fs::directory_iterator it(ph); it != end_it; ++it) {
            seq.push_back(it->filename());
        }
        return true;
    }

    template <typename Sequence> inline
    bool listdir(Sequence& seq, const boost::filesystem::wpath& wph)
    {
        namespace fs = boost::filesystem;
        boost::function_requires< boost::BackInsertionSequenceConcept<Sequence> >();

        fs::wdirectory_iterator end_it;
        for (fs::wdirectory_iterator it(wph); it != end_it; ++it) {
            seq.push_back(it->filename());
        }
        return true;
    }

    template <typename Func> inline
    Func listdir(const boost::filesystem::path& ph, Func func)
    {
        namespace fs = boost::filesystem;

        fs::directory_iterator end_it;
        for (fs::directory_iterator it(ph); it != end_it; ++it) {
            func(*it);
        }
        return func;
    }

    template <typename Func> inline
    Func listdir(const boost::filesystem::wpath& wph, Func func)
    {
        namespace fs = boost::filesystem;

        fs::wdirectory_iterator end_it;
        for (fs::wdirectory_iterator it(wph); it != end_it; ++it) {
            func(*it);
        }
        return func;
    }


    inline bool symlink(const boost::filesystem::path& src,
                   const boost::filesystem::path& dst)
    {
        boost::filesystem::create_symlink(src, dst);
        return true;
    }

    inline bool symlink(const boost::filesystem::wpath& src,
                  const boost::filesystem::wpath& dst)
    {
        boost::filesystem::create_symlink(src, dst);
        return true;
    }


    typedef boost::tuple< std::string,
                           std::list<std::string>,
                           std::list<std::string> > rdf_t;



    inline bool walk(std::list<rdf_t>& rdf, const boost::filesystem::path& ph)
    {
        namespace fs = boost::filesystem;

        bool cond = true;

        while (cond) {
            fs::directory_iterator end_it;
        }

        return true;
    }

    template <typename Func> inline
    Func walk(const boost::filesystem::path& ph, Func func)
    {
        namespace fs = boost::filesystem;

        fs::recursive_directory_iterator end_it;
        for (fs::recursive_directory_iterator it(ph); it != end_it; ++it) {
            func(*it);
        }
        return func;
    }

    template <typename Func> inline
    Func walk(const boost::filesystem::wpath& wph, Func func)
    {
        namespace fs = boost::filesystem;

        fs::wrecursive_directory_iterator end_it;
        for (fs::wrecursive_directory_iterator it(wph); it != end_it; ++it) {
            func(*it);
        }
        return func;
    }


    namespace path {

        inline std::string basename(const boost::filesystem::path& ph)
        {
            return ph.filename();
        }

        inline std::wstring basename(const boost::filesystem::wpath& wph)
        {
            return wph.filename();
        }


        inline std::string chextension(const boost::filesystem::path& ph, const std::string& new_ext)
        {
            return boost::filesystem::change_extension(ph, new_ext).string();
        }


        inline std::string dirname(const boost::filesystem::path& ph)
        {
            return ph.parent_path().string();
        }

        inline std::wstring dirname(const boost::filesystem::wpath& wph)
        {
            return wph.parent_path().string();
        }


        inline bool exists(const boost::filesystem::path& ph)
        {
            return boost::filesystem::exists(ph);
        }

        inline bool exists(const boost::filesystem::wpath& wph)
        {
            return boost::filesystem::exists(wph);
        }


        inline bool isabs(const boost::filesystem::path& ph)
        {
            return ph.is_complete();
        }

        inline bool isabs(const boost::filesystem::wpath& wph)
        {
            return wph.is_complete();
        }


        inline bool isfile(const boost::filesystem::path& ph)
        {
            return boost::filesystem::is_regular_file(ph);
        }

        inline bool isfile(const boost::filesystem::wpath& wph)
        {
            return boost::filesystem::is_regular_file(wph);
        }


        inline bool isdir(const boost::filesystem::path& ph)
        {
            return boost::filesystem::is_directory(ph);
        }

        inline bool isdir(const boost::filesystem::wpath& wph)
        {
            return boost::filesystem::is_directory(wph);
        }


        inline bool islink(const boost::filesystem::path& ph)
        {
            return boost::filesystem::is_symlink(ph);
        }

        inline bool islink(const boost::filesystem::wpath& wph)
        {
            return boost::filesystem::is_symlink(wph);
        }


        inline std::string normpath(const boost::filesystem::path& ph)
        {
            boost::filesystem::path temp(ph);
            return temp.normalize().string();
        }

        inline std::wstring normpath(const boost::filesystem::wpath& wph)
        {
            boost::filesystem::wpath temp(wph);
            return temp.normalize().string();
        }


        inline std::string stem(const boost::filesystem::path& ph)
        {
            return ph.stem();
        }

        inline std::wstring stem(const boost::filesystem::wpath& wph)
        {
            return wph.stem();
        }


        inline std::string extension(const boost::filesystem::path& ph)
        {
            return ph.extension();
        }

        inline std::wstring extension(const boost::filesystem::wpath& ph)
        {
            return ph.extension();
        }


        inline std::pair<std::string, std::string> split(const boost::filesystem::path& ph)
        {
            return std::make_pair(ph.parent_path().string(), ph.filename());
        }


        //bool check_boost_filesystem_path(const std::string& ph);

    } // namespace path
} } // namespace cppython::os

/*
bool os::path::check_boost_filesystem_path(const std::string& ph)
{
    using namespace std;
    boost::filesystem::path tph(ph);

    cout << "string >>> " << tph.string() << endl;
    cout << "file_string >>> " << tph.file_string() << endl;
    cout << "directory_string >>> " << tph.directory_string() << endl;

    cout << "external_file_string >>> " << tph.external_file_string() << endl;
    cout << "external_directory_string >>> " << tph.external_directory_string() << endl;

    cout << "root_name >>> " << tph.root_name() << endl;
    cout << "root_directory >>> " << tph.root_directory() << endl;

    cout << "root_path >>> " << tph.root_path() << endl;
    cout << " relative_path >>> " << tph.relative_path() << endl;

    cout << "branch_path >>> " << tph.branch_path() << endl;

    cout << "parent_path >>> " << tph.parent_path() << endl;
    cout << "filename >>> " << tph.filename() << endl;
    cout << "stem >>> " << tph.stem() << endl;
    cout << "extension >>> " << tph.extension() << endl;

    return true;
}
*/

#endif
