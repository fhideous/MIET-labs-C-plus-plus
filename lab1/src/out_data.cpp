//
// Created by fhideous on 16.03.2021.
//


#include "../hdrs/out_data.h"
#include "../hdrs/lab.h"


OutEmplrs::OutEmplrs(const std::vector<Employer> &emplrs) {_data = emplrs;}
OutEmplrs::OutEmplrs(const std::string &s,const std::vector<Employer> &emplrs)
{
	_data = emplrs;
	set_path_w(s);
}

void OutEmplrs::print_data()
{
	std::streambuf  *coutbuf = std::cout.rdbuf();
	if (_path_to_file_w.length())
		std::cout.rdbuf(_out.rdbuf());

	for (auto &n : _data)
		n.print_empl();
	std::cout.rdbuf(coutbuf);
}
