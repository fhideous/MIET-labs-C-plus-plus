//
// Created by fhideous on 04.04.2021.
//

#include "JSONReader.h"

void		JSONReader::open_path(std::string &path)
{
	_is_op = false;
	_in.open(path, std::ios::in);
	if (!_in)
		return ;
	else
		_is_op = true;
	_path_r = path;
	if (path.find(".json") != std::string::npos)
		_in >> json;
	else
		_is_op = false;
	_in.close();
}

void		JSONReader::fd_close() {json.clear(); _is_op = false; _path_r = "Nan";}

bool		JSONReader::is_open() const {return _is_op;}


void from_json(const nlohmann::json& j, Employer& empl)
{
	std:: string tmp;
	j.at("Name").get_to(tmp);
	empl.set_name(tmp);
	j.at("Year").get_to(tmp);
    empl.set_year(stoi(tmp));
	j.at("Sex").get_to(tmp);
	empl.set_gender(tmp);

}

bool  JSONReader::read(Employer &empl)
{
    int count;

    count = 0;
	empl = json[count].get<Employer>();
	count++;
	if (json[count + 1].empty())
		return false;
	else
		return true;
}

std::vector<Employer> JSONReader::read_all() {
	std::vector<Employer> empls;
    for(auto &i : json)
	{
		auto c = i.get<Employer>();
		empls.push_back(std::move(c));
    }
    empls[0].id_reset();
	return (empls);
}

/*
 * overloads
 */

JSONReader& operator >> (JSONReader &in, std::vector<Employer> &empls)
{
	for(auto &i : in.json)
	{
		auto c = i.get<Employer>();
		empls.push_back(std::move(c));
	}
	return in;
}

