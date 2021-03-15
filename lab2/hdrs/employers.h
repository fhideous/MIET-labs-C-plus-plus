//
// Created by fhideous on 05.03.2021.
//
#include "../hdrs/lab.h"
#include "../hdrs/employer.h"

#ifndef CPP_LAB_EMPLOYERS_H
#define CPP_LAB_EMPLOYERS_H

class Employers
{
public:
	Employers();
	Employers(const std:: string &);
	Employers(const std::vector<Employer> &);
	Employers(const std::vector<Employer> &, const std::string &,
		   const std::string &);
	Employers(const std::vector<Employer> &, const std::string &);

	~Employers() {_in.close();}

//	void print_emplrs();
	void add_emplrs();
	void set_emplrs(const std::vector<Employer> &empllrs) {_emplrs = empllrs;}
	void set_path_r(const std::string &path_r) {
		_in.open(path_r);
		if (!_in)
			std::cout << "Wrong input file";
		_path_to_file_r = path_r;
	}
	std::vector<Employer> get_emplrs()	{return _emplrs;}

private:
	std::string			_path_to_file_r;
	std::ifstream		_in;

	std::vector<Employer>	_emplrs;
};

#endif //CPP_LAB_EMPLOYERS_H
