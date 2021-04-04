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
	explicit AbstractReader(std::string &path): _path_r(path)
		{
			_in.open(_path_r, std::ios::in);
			if (!_in)
				_is_op = false;
			else
				_is_op = true;
		}

	virtual	Employer raed() = 0;

	bool is_open() const {return _is_op;}
	std::string get_path() const {return _path_r;}

protected:
	std::string		_path_r;
	std::ifstream	_in;
	bool 			_is_op;
};


#endif //LAB4_ABSTRACTREADER_H
