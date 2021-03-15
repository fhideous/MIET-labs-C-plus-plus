//
// Created by fhideous on 16.03.2021.
//

#include "../hdrs/lab.h"
#include "../hdrs/employer.h"

Employer::Employer() : _id(0), _name("-"),
					   _year(0), _gender("") {}

Employer::~Employer() {}

Employer::Employer(int id, const std::string &name, int year,
				   const std::string &gender) :
		_id(id), _name(name),
		_year(year), _gender(gender) {}

Employer::Employer(const std::string &from) {
	std::vector<std::string>	fr_split;
	static int					count = 1;

	fr_split = split(from, ';');
	if (fr_split.size() != 5)
	{
//		std::cout << "wrong number of arguments in " << to.size() + count << " line\n";
		count++;
		return ;
	}
	_id =stoi(fr_split[0]);
	_name = fr_split[1];
	_year = stoi(fr_split[2]);
	_gender= fr_split[3];
	if(set_gender(fr_split[3]))
	{
//		std::cout << "wrong gender in " << to.size() + count << " line\n";
		count++;
		return  ;
	}
}

void Employer::print_empl()
{
	std::cout << "ID: " << _id << "\n";
	std::cout << "Name: " << _name << "\n";
	std::cout << "Year: " << _year << "\n";
	std::cout << "SEX: " << _gender << "\n";
}
