//
// Created by fhideous on 04.04.2021.
//
//#include "AbstractReader.h"
#include "JSONReader.h"
#include "CSVReader.h"
#include "lab.h"

int main(int argc, char *argv[])
{
	std::string path  = "/home/fhideous/QT/lab4/1";
	CSVReader csv_rdr(path);
	if (csv_rdr.is_open())
	{
		Employer empl, empl2, empl3;
		empl = csv_rdr.read();
		empl2 = csv_rdr.read();
		empl3 = csv_rdr.read();
		empl.print_empl();
		empl2.print_empl();
		empl3.print_empl();
	}

	csv_rdr.read();
}