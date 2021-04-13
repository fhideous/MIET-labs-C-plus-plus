//
// Created by fhideous on 04.04.2021.
//

#include "CSVReader.h"

void		CSVReader::open_path(std::string &path)
{
	_in.open(path, std::ios::in);
	if (!_in)
		_is_op = false;
	else
		_is_op = true;
	_path_r = path;
}

void		CSVReader::fd_close() {_in.close(); _is_op = false; _path_r = "Nan";}

bool		CSVReader::is_open() const {return _is_op;}

bool 		CSVReader::read(Employer &empl)
{
	std::string					s;
	std::vector<std::string>	fr_split;
//	Employer					emp;

	std::getline(_in, s);
	fr_split = split(s, ';');
	if(!check_vector_csv(fr_split))
	{
		empl.set_name("Nan");
        empl.set_year(-1);
		empl.set_gender("KeK");
	}
	else
	{
		empl.set_name(std::move(fr_split[0]));
        empl.set_year(stoi(std::move(fr_split[1])));
        empl.set_gender(std::move(fr_split[2]));
	}
    if (_in.eof())
		return false;
	else
		return true;
}
//
//std::vector<Employer> CSVReader::read_all()
//{
//	std::vector<Employer> empls;
//	for(auto )
//
//}
