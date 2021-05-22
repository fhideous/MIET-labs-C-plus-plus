//
// Created by fhideous on 01.04.2021.
//

#ifndef CPP_LAB_STUDENT_H
#define CPP_LAB_STUDENT_H

#include "employer.h"
#include "lab.h"

class Student : public Employer
{
public:
	Student(const std::string &, const std::vector<std::string>  &);
	std::string repr() const;
private:
	std::string _course;
};


#endif //CPP_LAB_STUDENT_H
