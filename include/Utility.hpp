#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <string>
#include <sstream>

namespace zge
{
	template <class T>
	std::string toString(T x)
	{
		std::stringstream ss;
		ss << x;
		return ss.str();
	}
} //Namespace zge

#endif // UTILITY_HPP
