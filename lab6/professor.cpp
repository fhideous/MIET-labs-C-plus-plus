//
// Created by fhideous on 01.04.2021.
//

#include "professor.h"

Professor::Professor(const std::string &discipline, const std::vector<std::string> &data) :
		_discipline(discipline), Employer(data) {}


std::string Professor::repr() const {
	return ("Professor:\t\t" + _discipline + " " + _name
	+ " " + std::to_string(_year) + " "
	+ _gender);
}