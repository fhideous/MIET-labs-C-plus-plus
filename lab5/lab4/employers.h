//
// Created by fhideous on 05.03.2021.
//
//#include "../hdrs/lab.h"
//#include "../hdrs/employer.h"
#include "lab.h"
#include "employer.h"

#ifndef CPP_LAB_EMPLOYERS_H
#define CPP_LAB_EMPLOYERS_H

class Employers
{
public:
	Employers();
	Employers(const std:: string &);
    Employers(std::vector<Employer> &);
//	Employers(std::vector<Employer> &, const std::string &,
//		   const std::string &);
    Employers(std::vector<Employer> &, const std::string &);

	~Employers() {_in.close();}

	void add_emplrs();
	bool set_path_r(const std::string &path_r);
    void set_emplrs(std::vector<Employer> &empllrs) {_emplrs = std::move(empllrs);}
	std::string get_path() const {return _path_to_file_r;}
    std::vector<Employer>& get_emplrs() 	{return _emplrs;}
//    Employer get_emplr(int i) {return std::move(_emplrs[i]);};
    void add_emplr(Employer &&emplr) {_emplrs.push_back(std::move(emplr));}

private:
    std::string             _path_to_file_r;
    std::ifstream           _in;
	std::vector<Employer>	_emplrs;
};

#endif //CPP_LAB_EMPLOYERS_H
