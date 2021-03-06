#include "lab.h"
#include "employer.h"
#include "employers.h"
#include "Empl.h"
#include "Student.h"
#include "professor.h"
#include "out_data.h"
#include "JSONReader.h"
#include "CSVReader.h"


int main(int argc, char *argv[])
{
	std::string path = "../test";
	std::string JSONpath = "../1.json";
	CSVReader file(path);
	JSONReader JSONfile(JSONpath);
	if (!file.is_open() || !JSONfile.is_open())
	{
		std::cout << "One of file is wrong" << std::endl;
		return 1;
	}

	Employer empl;
	while  (file >> empl)
		std::cout << empl  << std::endl;
	std::cout << std::endl;
	file.fd_close();

	std::vector<Employer> emplrs;
	JSONfile >> emplrs;
	for (auto &employer : emplrs)
		std::cout << employer << std::endl;
	JSONfile.fd_close();
	return 0;
}

