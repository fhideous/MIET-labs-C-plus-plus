//
// Created by fhideous on 30.03.2021.
//

#include "lab.h"
#include "employers.h"
#include "out_data.h"
/*
 * file .csv must end with one empty line
 */




int main(int argc, char *argv[])
{

	std::string file_0 = "/home/fhideous/lab2/1";
	std::string str = "Vlad";


	std::vector<Employer> empls;
	Employers my_mplrs;
	Employer emp;

	my_mplrs.set_path_r(file_0);
	my_mplrs.add_emplrs();
	empls = my_mplrs.get_emplrs();

	int i = 0;
	for(auto &n : empls)
	{
		if (n.get_name() == str)
			break ;
		std :: string str_del = n.get_name();
		i++;
	}

	if (i < (int)empls.size()) {

		std:: cout << str;
	}
	return 1;
}

