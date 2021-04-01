//
// Created by fhideous on 16.03.2021.
//


//#include "../hdrs/lab.h"
//#include "../hdrs/employers.h"
#include "employers.h"
#include "lab.h"

Employers::Employers()  {}


Employers::Employers(const std::string &path_to_file_r)
{
	set_path_r(path_to_file_r);
}

Employers::Employers(const std::vector<Employer> &emplrs) :
		_emplrs(emplrs) {}

Employers::Employers(const std::vector<Employer> &emplrs,
					 const std::string &path_to_file_r) :
        _path_to_file_r(path_to_file_r),
        _emplrs(emplrs)
{
	set_path_r(path_to_file_r);
}

bool Employers::set_path_r(const std::string &path_r) {
	_in.open(path_r, std::ios::out);
	if (!_in)
		return true;
	_path_to_file_r = path_r;
	return false;
}

void Employers::add_emplrs()
{
	std::string			s;
	std::vector<std::string>	fr_split;
    int i = 0;
	while (std::getline(_in, s))
	{
		fr_split = split(s, ';');
        if (!check_vector_csv(fr_split))
			continue;
        Employer			empl(i, fr_split);
		_emplrs.push_back(std::move(empl));
        i++;
	}

}
