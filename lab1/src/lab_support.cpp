//
// Created by fhideous on 01.03.2021.
//

#include "../hdrs/lab.h"

std::vector<std::string> split(const std::string& str, char delim)
{
	std::vector<std::string> tokens;
	std::string sub_str;

	size_t start = 0, end = str.find(delim, start);
	while (end != std::string::npos)
	{
		end = str.find(delim, start);
		sub_str = str.substr(start, (end - start));
		if (sub_str !=  "")
			tokens.push_back(sub_str);
		start = end + 1;
	}
	return tokens;
}