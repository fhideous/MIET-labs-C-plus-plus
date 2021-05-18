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

bool		CSVReader::is_open()  const{return _is_op;}

bool 		CSVReader::read(Employer &empl)
{
	std::string					s;
	std::vector<std::string>	fr_split;

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
    return true;
}

/*
 * overloads
 */

CSVReader& operator >> (CSVReader &in, Employer &empl)
{
	std::vector<std::string> data_sp;
	std::string data;
	in._in >> data;
	data_sp = split(data, ';');
	if(data_sp.size() != 3)
		return in;
    empl.set_name(data_sp[0]);
	empl.set_year(stoi(data_sp[1]));
	empl.set_gender(data_sp[2]);
	empl.set_id(empl.GET_ID());
	return in;
}

CSVReader::operator bool()
{
	return (!_in.eof());
}
