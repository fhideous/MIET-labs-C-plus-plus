//
// Created by fhideous on 04.04.2021.
//
#ifndef CPP_LAB4_CSVREADER_H
#define CPP_LAB4_CSVREADER_H

#include "AbstractReader.h"

class CSVReader: public AbstractReader
{
public:
	explicit CSVReader(std::string &path) : AbstractReader(path)
	{
		_in.open(_path_r, std::ios::in);
		if (!_in)
			_is_op = false;
		else
			_is_op = true;
	}
	Employer	read();

};
#endif //CPP_LAB4_CSVREADER_H
