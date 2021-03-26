//
// Created by fhideous on 05.03.2021.
//
//#include "../hdrs/lab.h"
#include "lab.h"

#ifndef CPP_LAB_EMPLOYER_H
#define CPP_LAB_EMPLOYER_H

class Employer
{
public:
	Employer();
	Employer(const std::string &);
	Employer(int id, const std::string &, int, const std::string &);
	~Employer();

	void set_id(int id) { _id = id;}
	void set_name(const std::string &name) { _name = name;}
	void set_year(int year) { _year = year;}
	int set_gender(const std::string &gender) {
		if (gender == "MALE" ||
			gender == "HELICOPTER" ||
			gender ==	"FEMALE")
			_gender = gender;
		else
			return(1);
		return(0);
	}
    std::string     get_name() { return _name; }
    int             get_id() {return _id;}
    std::string     get_gender() {return _gender;}
    int             get_year() {return _year;}
	void print_empl();

private:
	int					_id;
	std::string			_name;
	int 				_year;
	std::string			_gender;

};

#endif //CPP_LAB_EMPLOYER_H
