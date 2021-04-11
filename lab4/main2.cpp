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
		printf("\n%d\n", csv_rdr.is_open());
		empl2 = csv_rdr.read();
		empl3 = csv_rdr.read();
		empl.print_empl();
		empl2.print_empl();
		empl3.print_empl();
		csv_rdr.fd_close();
		std::cout << csv_rdr.get_path();

		printf("\n%d\n", csv_rdr.is_open());
		csv_rdr.open_path(path);
		printf("\n%d\n", csv_rdr.is_open());
		empl = csv_rdr.read();
		empl.print_empl();
		csv_rdr.fd_close();
	}
	std::string json_file = "/home/fhideous/QT/1.json";
	JSONReader json(json_file);
		Employer empl, empl2;
		empl = json.read();
		empl2 = json.read();
		empl.print_empl();
		empl2.print_empl();
	json.fd_close();
	json.open_path(json_file);
	if(json.is_open())
	{
		empl = json.read();
		empl.print_empl();
		json.fd_close();
	}
}