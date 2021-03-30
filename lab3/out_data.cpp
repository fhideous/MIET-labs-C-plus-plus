//
// Created by fhideous on 16.03.2021.
//

//#include "../hdrs/lab.h"
//#include "../hdrs/out_data.h"
#include "out_data.h"
#include "lab.h"

OutEmplrs::OutEmplrs(const std::string &path) {
	set_path_w(path);
}

OutEmplrs::OutEmplrs(const std::string &path ,const std::vector<Employer> &emplrs)
{
	set_path_w(path);
	print_data(emplrs);
}

bool OutEmplrs::set_path_w(const std::string &path_w) {
	_out.open(path_w,  std::ios_base::app);
	if (!_out)
		return true;
	_path_to_file_w = path_w;
	return false;
}

void OutEmplrs::print_data(const std::vector<Employer> &data) const
{
	std::streambuf  *coutbuf = std::cout.rdbuf();
	if (_path_to_file_w.length())
		std::cout.rdbuf(_out.rdbuf());

	for (auto &n : data)
		n.print_empl();
	std::cout.rdbuf(coutbuf);
}
