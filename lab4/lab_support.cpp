//
// Created by fhideous on 01.03.2021.
//

//#include "../hdrs/lab.h"
#include "lab.h"

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

bool check_vector_csv(const std::vector<std::string> &vec)
{
	std::vector<std::string> gen = {"MALE", "FEMALE", "HELICOPTER"};
    if (vec.size() != 3)
		return false;
	if (vec[2] != gen[1] && vec[2] != gen[2] && vec[2] != gen[0])
		return false;
	return true;
}
