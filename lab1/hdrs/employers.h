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

Employers::Employers()  {}

Employers::Employers(const std::string &path_to_file_r) :
		_path_to_file_r(path_to_file_r){}

Employers::Employers(const std::vector<Employer> &emplrs) :
		_emplrs(emplrs) {}

Employers::Employers(const std::vector<Employer> &emplrs,
					 const std::string &path_to_file_r) :
		_emplrs(emplrs),
		_path_to_file_r(path_to_file_r)
{
	_in.open(path_to_file_r);
	if (!_in)
		std::cout << "Wrong input file";
}

Employers::Employers(const std::vector<Employer> &emplrs,
					 const std::string &path_to_file_r,
					 const std::string &path_to_file_w) :
		_emplrs(emplrs),
		_path_to_file_r(path_to_file_r), _path_to_file_w(path_to_file_w)
{
	_in.open(path_to_file_r);
	if (!_in)
		std::cout << "Wrong input file";
	_out.open(path_to_file_w);
	if (!_out)
		std::cout << "Wrong output file";
}

void Employers::print_emplrs()
{
	std::streambuf  *coutbuf = std::cout.rdbuf();
	if (_path_to_file_w.length())
		std::cout.rdbuf(_out.rdbuf());

	for (auto &n : _emplrs)
		Employer::print_empl(n);

	std::cout.rdbuf(coutbuf);
}

void Employers::add_node(std::vector<Employer> &to, const std::string &from)
{
	std::vector<std::string>	fr_split;
	Employer		new_empl;
	static int 		count = 1;

	fr_split = split(from, ';');
	if (fr_split.size() != 5)
	{
		std::cout << "wrong number of arguments in " << to.size() + count << " line\n";
		count++;
		return ;
	}
	new_empl.set_id(stoi(fr_split[0]));
	new_empl.set_name(fr_split[1]);
	new_empl.set_year(stoi(fr_split[2]));
	if(new_empl.set_gender(fr_split[3]))
	{
		std::cout << "wrong gender in " << to.size() + count << " line\n";
		count++;
		return  ;
	}
	to.push_back(new_empl);
}

void Employers::add_emplrs()
{
	std::string			s;

	while (std::getline(_in, s))
		add_node(_emplrs, s);

}

#endif //CPP_LAB_EMPLOYERS_H
