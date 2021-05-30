//
// Created by fhideous on 04.04.2021.
//

#ifndef ABSTRACT_READER_H
#define ABSTRACT_READER_H

#include "lab.h"
#include "employer.h"
//#include "JSONReader.h"
//#include "CSVReader.h"

class AbstractReader {
public:
	virtual	bool raed(Employer &) {}
	virtual bool is_open() const {}
//	virtual std::vector<Employer> read_all() {}
	std::string get_path() const {return _path_r;}
protected:

	AbstractReader(std:: string &path) : _path_r(path) {}
	std::string		_path_r;
	std::ifstream	_in;
	bool 			_is_op;
};
#endif //LAB4_ABSTRACTREADER_H
