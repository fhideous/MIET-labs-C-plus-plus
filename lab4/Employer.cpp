//
// Created by fhideous on 04.04.2021.
//
#include "Employer.h"
#include "lab.h"

//
// Created by fhideous on 16.03.2021.
//

#include "lab.h"
#include "Employer.h"

int Employer::s_id = 0;

Employer::Employer() : _id(0), _name("-"),
					   _year(""), _gender("") {}

//Employer::Employer(const Employer &obj) : _id(obj._id), _name(obj._name),
//										  _year(obj._year), _gender(obj._gender){}

Employer::Employer(Employer &&obj) : _id(obj._id), _name(obj._name),
									 _year(obj._year), _gender(obj._gender)
{
	obj._id = 0;
	obj._name = "";
	obj._year = "";
	obj._gender = "";
}

Employer::~Employer() {}

Employer::Employer(const std::string &name, const std::string &year,
				   const std::string &gender) :
		_id(GET_ID()), _name(name),
		_year(year), _gender(gender) {}


Employer::Employer(const std::vector<std::string> &fr_split) {
	_id = GET_ID();
	_name = fr_split[0];
	_year = fr_split[1];
	if(set_gender(fr_split[2]))
	{
//		Wrong Gender
		_gender = "NaN";
	} else
		_gender = fr_split[2];
}

Employer::Employer(int id, const std::vector<std::string> &fr_split) {
	_id = id;
	_name = fr_split[0];
	_year = stoi(fr_split[1]);
	if(set_gender(fr_split[2]))
	{
//		Wrong Gender
		_gender = "NaN";
	} else
		_gender = fr_split[2];
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
	obj._year = "";
	obj._gender = "";
}

void Employer::print_empl() const
{
//    std::cout << _id << ";";
	std::cout << _name << ";";
	std::cout << _year << ";";
	std::cout << _gender << ";\n";
}