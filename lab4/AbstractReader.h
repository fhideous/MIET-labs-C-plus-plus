//
// Created by fhideous on 04.04.2021.
//

#ifndef ABSTRACT_READER_H
#define ABSTRACT_READER_H

#include "lab.h"
#include "Employer.h"
//#include "JSONReader.h"
//#include "CSVReader.h"

class AbstractReader {
public:
	virtual	Employer raed()
	{
		_is_op = false;
		Employer emp;
		return std::move(emp);
	}
	bool is_open() const {return _is_op;}
	std::string get_path() const {return _path_r;}
protected:

	AbstractReader(std:: string &path) : _path_r(path) {}
	std::string		_path_r;
	std::ifstream	_in;
	bool 			_is_op;
};
#endif //LAB4_ABSTRACTREADER_H
