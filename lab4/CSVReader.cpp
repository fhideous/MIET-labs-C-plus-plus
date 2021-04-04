//
// Created by fhideous on 04.04.2021.
//

#include "CSVReader.h"

Employer CSVReader::read()
{
	std::string					s;
	std::vector<std::string>	fr_split;
	Employer					emp;

	std::getline(_in, s);
	fr_split = split(s, ';');
	if(!check_vector_csv(fr_split))
	{
		emp.set_name("Nan");
		emp.set_year("-1:-1:-1");
		emp.set_gender("KeK");
	}
	else
	{
		emp.set_name(fr_split[0]);
		emp.set_year(fr_split[1]);
		emp.set_gender(fr_split[2]);
	}
	return std::move(emp);
}