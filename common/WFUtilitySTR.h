#pragma once
#include <string>

class WF_STR
{
public:
	static template < typename T > std::string to_string(const T& n)
	{
		std::ostringstream stm;
		stm << n;
		return stm.str();
	}

private:
};

