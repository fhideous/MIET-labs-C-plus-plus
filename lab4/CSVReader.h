//
// Created by fhideous on 04.04.2021.
//

#ifndef CPP_LAB4_CSVREADER_H
#define CPP_LAB4_CSVREADER_H

#include "AbstractReader.h"

class CSVReader: public AbstractReader
{
public:

	explicit CSVReader(std::string &path):
			AbstractReader(path) {}
	Employer	read();

private:
};


#endif //CPP_LAB4_CSVREADER_H
