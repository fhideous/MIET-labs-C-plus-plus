//
// Created by fhideous on 16.03.2021.
//

//#include "../hdrs/lab.h"
//#include "../hdrs/employer.h"
#include "lab.h"
#include "employer.h"

int Employer::s_id = 0;

Employer::Employer() : _id(GET_ID()), _name("-"),
					   _year(0), _gender("") {s_id++;}

Employer::Employer(const Employer &obj) : _id(GET_ID()), _name(obj._name),
										  _year(obj._year), _gender(obj._gender){}

Employer::Employer(Employer &&obj) : _id(GET_ID()), _name(obj._name),
									 _year(obj._year), _gender(obj._gender)
{
    obj._name = "";
    obj._year = 0;
    obj._gender = "";
}

Employer::~Employer() {}

Employer::Employer(const std::string &name, int year,
				   const std::string &gender) :
		_id(GET_ID()), _name(name),
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
	_id = stoi(fr_split[0]);
	_name = fr_split[1];
	_year = stoi(fr_split[2]);
	if(set_gender(fr_split[3]))
	{
//		Wrong Gender
	_gender = "NaN";
	} else
		_gender = fr_split[3];
}

void Employer::operator= (const Employer &obj)
{
    _id = obj._id;
    _name = obj._name;
    _year = obj._year;
    _gender = obj._gender;
}

void Employer::operator= (Employer &&obj)
{
    _id = obj._id;
    _name = obj._name;
    _year = obj._year;
    _gender = obj._gender;

    obj._id = 0;
    obj._name = "";
    obj._year = 0;
    obj._gender = "";
}

//int Employer::check_valid_id(int id)
//{

//}

void Employer::print_empl() const
{
    std::cout << _id << ";";
    std::cout << _name << ";";
    std::cout << _year << ";";
    std::cout << _gender << ";\n";
}
