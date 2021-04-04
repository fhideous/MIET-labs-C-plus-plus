//
// Created by fhideous on 04.04.2021.
//

#include "CSVReader.h"

CSVReader::CSVReader(std::string &path)
		:AbstractReader(path)
{
	_in.open(_path_r, std::ios::in);
	if (!_in)
		_is_op = false;
	else
		_is_op = true;
}

std::string CSVReader::get_path() const
{	return _path_r;	}

bool CSVReader::is_open() const
{	return _is_op;	}

Employer CSVReader::read()
{
	std::string		s;
	std::vector<std::string>		fr_split;
	Employer emp;

	std::getline(_in, s);
	fr_split = split(s, ';');
	if(!check_vector_csv(fr_split))
	{
		emp.set_name("Nan");
		emp.set_year("-1:-1:-1");
	}
	else
	{
		emp.set_name(fr_split[0]);
		emp.set_year(fr_split[1]);
		emp.set_gender(fr_split[2]);
	}
	return std::move(emp);
}