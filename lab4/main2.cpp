#include "lab.h"
#include "employer.h"
#include "employers.h"
#include "Empl.h"
#include "Student.h"
#include "professor.h"
#include "out_data.h"
#include "JSONReader.h"
#include "CSVReader.h"
/*
 * file .csv must end with one empty line
 */


int main(int argc, char *argv[])
{
	std::string path = "../test";
	CSVReader file(path);
	if (!file.is_open())
	{
		std::cout << "Wrong file" << std::endl;
		return 1;
	}
	Employer empl;
	file >> empl;
	std::cout << empl;
	return 1;
}

