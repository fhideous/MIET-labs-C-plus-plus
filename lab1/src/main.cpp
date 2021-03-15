
#include "../hdrs/lab.h"
#include "../hdrs/employers.h"
#include "../hdrs/out_data.h"
/*
 * file .csv must end with one empty line
 */




int main()
{
	std::string file_0 = "../csv.csv";
	std::string file_1 = "../1";
	std::string file_2 = "../2";

	Employers emy_mplrs;

	emy_mplrs.set_path_r(file_0);
	emy_mplrs.add_emplrs();


	OutEmplrs print_emp(emy_mplrs.get_emplrs());
	print_emp.print_data();

	print_emp.set_path_w(file_1);

	print_emp.print_data();

    return 0;
}
