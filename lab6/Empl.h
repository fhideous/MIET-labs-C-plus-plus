//
// Created by fhideous on 01.04.2021.
//

#ifndef CPP_LAB_EMPL_H
#define CPP_LAB_EMPL_H

#include "employer.h"
class Empl : public Employer{

public :
	Empl(const std::string &, const std::vector<std::string>  &);
	std::string repr() const;
private:
	std::string _salary;

};


#endif //CPP_LAB_EMPL_H
