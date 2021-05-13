//
// Created by fhideous on 01.04.2021.
//

#include "Empl.h"

Empl::Empl(const std::string &salary, const std::vector<std::string> &data) :
            Employer(data), _salary(salary) {}

std::string Empl::repr() const {
	return ("Just an employer:\t" + _salary + " " + _name + " "
			+ std::to_string(_year) + " "
			+ _gender);
}
