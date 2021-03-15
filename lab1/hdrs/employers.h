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

	~Employers() {_in.close(); _out.close();};

	void print_emplrs();
	void add_emplrs();
	void set_emplrs(const std::vector<Employer> &empllrs) {_emplrs = empllrs;}
	void set_path_r(const std::string &path_r) {
		_in.open(path_r);
		if (!_in)
			std::cout << "Wrong input file";
		_path_to_file_r = path_r;
	}
	void set_path_w(const std::string &path_w) {
		_out.open(path_w);
		if (!_out)
			std::cout << "Wrong output file";
		_path_to_file_w = path_w;
	}
	std::vector<Employer> get_emplrs()	{return _emplrs;}

private:
	void add_node(std::vector<Employer> &, const std::string &);
	std::string			_path_to_file_r;
	std::string			_path_to_file_w;

	std::ofstream		_out;
	std::ifstream		_in;

	std::vector<Employer>	_emplrs;
};

#endif //CPP_LAB_EMPLOYERS_H
