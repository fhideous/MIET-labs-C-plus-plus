//
// Created by fhideous on 01.03.2021.
//

#include "../hdrs/lab0.h"

int		check_errors(int n, int line)
{
	if (n == 1)
		std::cout << "Wrong file\n";
	if (n == 2)
		std::cout << "wrong number of arguments in " << line << " line\n";
	if (n == 3)
		std::cout << "wrong gender in " << line << " line\n";
	return (1);
}


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

int set_gender(std::string *to_gender, const std::string from_str)
{
	if (from_str == "MALE" ||
		from_str == "HELICOPTER" ||
		from_str ==	"FEMALE")
		*to_gender = from_str;
	else
		return(1);
	return(0);
}

int		add_node(std::vector<node> *to, const std::string from, int line)
{
	std::vector<std::string>	fr_split;
	node						new_nd;

	fr_split = split(from, ';');
	if (fr_split.size() != 5)
	{
		check_errors(2, line);
		return (0);
	}
	new_nd.n = stoi(fr_split[0]);
	new_nd.name = fr_split[1];
	new_nd.year = stoi(fr_split[2]);
	if(set_gender(&new_nd.gender, fr_split[3]))
	{
		check_errors(3, line);
		return(0);
	}
	to->push_back(new_nd);
	return (0);
}

void	print_node(const node &employer)
{
	std::cout << "------------\n";
	std::cout << "ID: " << employer.n << "\n";
	std::cout << "Name: " << employer.name << "\n";
	std::cout << "Year: " << employer.year << "\n";
	std::cout << "SEX: " << employer.gender << "\n";
	std::cout << "------------\n";
}