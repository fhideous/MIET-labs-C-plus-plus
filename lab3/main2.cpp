//
// Created by fhideous on 30.03.2021.
//

#include "lab.h"
#include "employer.h"
#include "employers.h"
#include "out_data.h"
/*
 * file .csv must end with one empty line
 */




int main(int argc, char *argv[])
{
	std::string file_0 = "/home/fhideous/lab2/lab3/1";

	std::vector<Employer> empls;
	Employers my_mplrs;

	if (my_mplrs.set_path_r(file_0))
	{
		return 432;
	}
	my_mplrs.add_emplrs();
	empls = my_mplrs.get_emplrs();

	int i = 0;
	for(auto &n : empls)
	{
		i++;
	}

//	std::vector<Employer> empls;
//	Employers my_mplrs;
//
//	if(my_mplrs.set_path_r(file_0))
//		std::cout << "Can't read";
//	my_mplrs.add_emplrs();
//
//	Employer empl2("Vlad", 12, "MALE");
//	Employer empl3("Vlad", 1124, "MALE");
//
//	empls = my_mplrs.get_emplrs();
//	Employer emp(std::move(empls[0]));
//	int ij = emp.get_id();
//	empl2 = std::move(emp);
//	int asd = empl2.get_id();
//	int i = 0;
//	for(auto &n : empls)
//	{
//		if (n.get_name() == str)
//			break ;
//		std :: string str_del = n.get_name();
//		i++;
//	}
//	if (i < (int)empls.size()) {
//
//		std:: cout << str;
//	}
	return 1;
}

