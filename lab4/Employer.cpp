//
// Created by fhideous on 04.04.2021.
//
#include "Employer.h"
#include "lab.h"

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
	if (check_vector_csv(fr_split))
	{
		_id = GET_ID();
		_name = fr_split[0];
		_year = fr_split[1];
		_gender = fr_split[2];

	}
	else
	{
		_id = -1;
		_name = "NaN";
		_year = "-1:-1:-1";
		_gender = "NaN";
	}
}

Employer::Employer(int id, const std::vector<std::string> &fr_split) {
	if (check_vector_csv(fr_split))
	{
		_id = id;
		_name = fr_split[0];
		_year = fr_split[1];
		_gender = fr_split[2];
	}
	else
	{
		_id = -1;
		_name = "NaN";
		_year = "-1:-1:-1";
		_gender = "NaN";
	}
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