//
// Created by fhideous on 04.04.2021.
//

#ifndef ABSTRACT_READER_H
#define ABSTRACT_READER_H

#include "lab.h"
#include "employer.h"

class AbstractReader {
public:
    virtual	bool read(Employer &) = 0;
    virtual bool is_open() const = 0;
//	virtual std::vector<Employer> read_all();
	std::string get_path() const {return _path_r;}
    AbstractReader(std:: string &path) : _path_r(path) {}


protected:
	std::string		_path_r;
	std::ifstream	_in;
	bool 			_is_op;
};
#endif
