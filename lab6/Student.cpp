//
// Created by fhideous on 01.04.2021.
//

#include "Student.h"

Student::Student(const std::string &course, const std::vector<std::string> &data) :
		_course(course), Employer(data)  {}

std::string Student::repr() const {
	return ("Student:\t\t" + _course +  " " +  _name +
			" " + 	std::to_string(_year) + " " +
			_gender);
}