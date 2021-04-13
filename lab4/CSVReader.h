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
		open_path(path);
	}
	void 		fd_close();
	void		open_path(std::string &path);
	Employer	read();
	bool		is_open() const;
};
#endif //CPP_LAB4_CSVREADER_H
