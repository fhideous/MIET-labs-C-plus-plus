//
// Created by fhideous on 16.03.2021.
//

//#include "../hdrs/lab.h"
//#include "../hdrs/employer.h"
#include "lab.h"
#include "employer.h"

int Employer::s_id = 0;

Employer::Employer() : _id(GET_ID()), _name("-"),
                       _year(0), _gender("") {}

//Employer::Employer(const Employer &obj) : _id(obj._id), _name(obj._name),
//										  _year(obj._year), _gender(obj._gender){}

Employer::Employer(Employer &&obj) : _id(obj._id), _name(obj._name),
									 _year(obj._year), _gender(obj._gender)
{
	obj._id = 0;
    obj._name = "";
    obj._year = 0;
    obj._gender = "";
}

Employer::~Employer() {}

//Employer::Employer(const std::string &name, int year,
//				   const std::string &gender) :
//		_id(GET_ID()), _name(name),
//		_year(year), _gender(gender) {}


Employer::Employer(const std::vector<std::string> &fr_split) {
//	_id = GET_ID();
	_name = fr_split[0];
	_year = stoi(fr_split[1]);
    _gender = fr_split[2];
}

Employer::Employer(int id, const std::vector<std::string> &fr_split) {
    _id = id;
    _name = fr_split[0];
    _year = stoi(fr_split[1]);
    _gender = fr_split[2];
    }

//void Employer::operator= (const Employer &obj)
//{
//    _id = obj._id;
//    _name = obj._name;
//    _year = obj._year;
//    _gender = obj._gender;
//}

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

void Employer::print_empl() const
{
//    std::cout << _id << ";";
    std::cout << _name << ";";
    std::cout << _year << ";";
    std::cout << _gender << ";\n";
}

std::string Employer::repr() const
{
	return "Parent";
};

/*
 * overloads
 */

std::ostream& operator<< (std::ostream &out, const Employer &empl)
{
	out <<  empl._id << ";" << empl._name << ";" << empl._year << ";" << empl._gender << ";";
	return out;
}