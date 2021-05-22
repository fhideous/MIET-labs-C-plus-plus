#include "lab.h"
#include "employer.h"
#include "Empl.h"
#include "Student.h"
#include "professor.h"
#include "out_data.h"
#include "JSONReader.h"
#include "CSVReader.h"
#include "CsvException.h"


int main(int argc, char *argv[])
{
	/*std::string path = "../test";
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
	return 0;*/
	std::vector<Employer> emplrs;
	std::vector<std::string> substr;
	std::string path = "/home/fhideous/CLionProjects/lab6/1.csv";
	substr = split(path, '.');

	if (substr.back() == "csv")
	{
		CSVReader file(path);
		if (!file.is_open())
		{
			std::cout << "Wrong reading file";
			return 1;
		}
		Employer empl;
		int	n = 1;
		try
		{
			while (file >> empl)
			{
				std::cout <<empl.get_id() << "\t" << empl.get_name() << "\t" <<empl.get_year() << std::endl;
				emplrs.push_back(std::move(empl));
				n++;
			}
		}
		catch(CsvException &ex)
		{
			std::cout << ex.what() << ". Line № " << n << std::endl;
		}
		empl.id_reset();

	}
}

