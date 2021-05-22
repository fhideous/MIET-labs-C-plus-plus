//
// Created by fhideous on 01.04.2021.
//

#ifndef CPP_LAB_PROFESSOR_H
#define CPP_LAB_PROFESSOR_H

#include "lab.h"
#include "employer.h"
class Professor : public Employer{

public :
	Professor(const std::string &, const std::vector<std::string>  &);
	std::string repr() const;
private:
	std::string _discipline;

};


#endif //CPP_LAB_PROFESSOR_H
