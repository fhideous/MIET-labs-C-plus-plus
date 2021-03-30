//
// Created by fhideous on 16.03.2021.
//

//#include "../hdrs/lab.h"
//#include "../hdrs/employer.h"
#include "lab.h"
#include "employer.h"

Employer::Employer() : _id(0), _name("-"),
					   _year(0), _gender("") {}

Employer::~Employer() {}

Employer::Employer(int id, const std::string &name, int year,
				   const std::string &gender) :
		_id(id), _name(name),
		_year(year), _gender(gender) {}

Employer::Employer(const std::string &from) {
	std::vector<std::string>	fr_split;

	fr_split = split(from, ';');
	if (fr_split.size() != 4)
	{
//		Neeed Erroor
		_id = -1;
		_name = "NaN";
		_year = -1;
		_gender = "NaN";
		return ;
	}
	_id =stoi(fr_split[0]);
	_name = fr_split[1];
	_year = stoi(fr_split[2]);
	if(set_gender(fr_split[3]))
	{
//		Wrong Gender
	_gender = "NaN";
	} else
		_gender = fr_split[3];
}

void Employer::print_empl()
{
    std::cout << _id << ";";
    std::cout << _name << ";";
    std::cout << _year << ";";
    std::cout << _gender << ";\n";
}
