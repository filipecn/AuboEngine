#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <locale> 

namespace utils 
{
	template <class T>
	class Vec3{
		public:
			T x, y, z;
	};
	
	std::string upperString(std::basic_string<char> str);

}

#endif
