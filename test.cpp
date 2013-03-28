
#include "cppython/cppython.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	using namespace std;
	using namespace cppython;
	//using namespace pypp::stralg;
/*
	vector<string> flst;
	os::listdir(flst, "/home/ubuntu/MyLib/cppython");
	print(flst);

	namespace fs = boost::filesystem;
	fs::path pp("/home/ubuntu/MyLib/cppython");
	fs::recursive_directory_iterator end_it;
	for (fs::recursive_directory_iterator it(pp); it != end_it; ++it) {
		cout << *it << endl;
	}

	os::remove("tmp");


	os::path::check_boost_filesystem_path("/home/ubuntu/lib/cpp/MyLib/cppython/os.hpp");
*/
	string s("this is Test program."), ss("Thisistest"), di("11111"), t("abcde");
	string cs = s|capitalize();
	std::cout << cs << "\n";


	vector<string> vec;
	vec = s|split<vector<string> >(" ");
//	cout << ("1"|zfill(3)) << "\n";
	print(vec);

	//cout << os::getenv("HOME") << endl;
	std::pair<string, string> ph = os::path::split("/home/ubuntu/lib/cpp/MyLib/cppython/os.hpp");
	cout << ph.first << " " << ph.second << endl;

	cout << os::abspath("core.hpp") << endl;

	cout << ("TesT PrGram"|swapcase()) << endl;

	//cout << stralg::center(t, 20) << "end" << endl;
	//cout << stralg::center("abcde", 20, "+") << "end" << endl;
	string ct = t|center(20, "%");
	cout << ct << "end" << endl;
	cout << (t|center(20)) << "end" << endl;
	cout << (t|center(20, "+")) << "end" << endl;

	cout << (t|ljust(20)) << "end" << endl;
	cout << ("abcde"|ljust(20, "+")) << "end" << endl;

	cout << ("   www.example.com   "|strip()) << endl;
	cout << ("   www.example.com   "|rstrip()) << endl;
	cout << ("   www.example.com   "|lstrip()) << endl;
	cout << ("www.example.com"|lstrip("wce.")) << endl;

	cout << (t|rjust(20)) << "end" << endl;
	cout << ("abcde"|rjust(20, "+")) << "end" << endl;

	cout << (slice(s, 3, -3)|upper()) << endl;
	cout << (s|capitalize()) << endl;
	cout << (di|isdigit()) << endl;
	cout << (ss|istitle()) << endl;
	cout << (ss|isalpha()) << endl;
	//cout << ("12"|zfill(5)) << endl;

	cout << boost::algorithm::all("", boost::algorithm::is_digit()) << endl;
	cout << typeid(boost::range_value<std::string>::type).name() << endl;
	cout << typeid(slice(s, 1, -1)).name() << endl;

	cout << (""|isdigit()) << endl;
	cout << ("afeaf10"|islower()) << endl;
	cout << slice(s, 2, -2) << endl;
	cout << slice(s, 3) << endl;

	boost::range_difference<string>::type r = (s|find("isi"));
	cout << typeid(r).name() << endl;
	boost::range_difference<string>::type rr = (s|find("is"));
	boost::range_difference<string>::type ir = (s|rfind("is"));
	//print(r);
	cout << r << endl;
	cout << rr << endl;
	cout << ir << endl;
	print(slice(s, rr, -1));
	print(slice(s, ir, -1));

	cout << ("1"|zfill(4)) << "\n";

	return 0;
}
