//
// Created by fhideous on 04.04.2021.
//
#ifndef CPP_LAB4_CSVREADER_H
#define CPP_LAB4_CSVREADER_H

#include "AbstractReader.h"

class CSVReader:AbstractReader {
public:
	CSVReader() = default;
	CSVReader(std::string &);
	~CSVReader() = default;

	std::string		get_path() const;
	bool			is_open() const;
	Employer		read();

private:
};


#endif //CPP_LAB4_CSVREADER_H
