
#include "../hdrs/lab.h"
#include "../hdrs/employers.h"

/*
 * file .csv must end with one empty line
 */

int main()
{
	std::string file_0 = "../csv.csv";
	std::string file_1 = "../1";
	std::string file_2 = "../2";

	std::vector<Employer> empls;
	Employers emy_mplrs;

	emy_mplrs.set_emplrs(empls);
	emy_mplrs.set_path_r(file_0);
	emy_mplrs.set_path_w(file_1);
	emy_mplrs.add_emplrs();
	empls = emy_mplrs.get_emplrs();
	emy_mplrs.print_emplrs();

	Employers my_empl(empls);

	my_empl.print_emplrs();

    return 0;
}
