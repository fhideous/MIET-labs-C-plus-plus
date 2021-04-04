//
// Created by fhideous on 04.04.2021.
//

#ifndef LAB4_ABSTRACTREADER_H
#define LAB4_ABSTRACTREADER_H

#include "lab.h"
#include "Employer.h"

class AbstractReader {
protected:
	AbstractReader(std::string &path):
			_path_r(path){}
	virtual Employer raed() = 0;
	virtual bool is_open() = 0;

	std::string		_path_r;
	std::ifstream	_in;
	bool 			_is_op;
};


#endif //LAB4_ABSTRACTREADER_H
