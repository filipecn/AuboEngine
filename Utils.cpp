#include "Utils.h"

namespace utils
{
	std::string upperString(std::basic_string<char> str){
		std::string s;
		std::locale loc;
		for (std::string::size_type i=0; i<str.length(); ++i)
			s += std::toupper(str[i],loc);
		return s;
	}

}
