
#include "../hdrs/lab.h"
#include "../hdrs/employers.h"

/*
 * file .csv must end with one empty line
 */


Employer::Employer() : _id(0), _name("-"),
					   _year(0), _gender("") {}

Employer::~Employer() {}

Employer::Employer(int id, const std::string &name, int year,
				   const std::string &gender) :
		_id(id), _name(name),
		_year(year), _gender(gender) {}

Employer::Employer(const std::string &from) {
	std::vector<std::string>	fr_split;
	static int					count = 1;


	fr_split = split(from, ';');
	if (fr_split.size() != 5)
	{
//		std::cout << "wrong number of arguments in " << to.size() + count << " line\n";
		count++;
		return ;
	}
	_id =stoi(fr_split[0]);
	_name = fr_split[1];
	_year = stoi(fr_split[2]);
	_gender= fr_split[3];
	if(set_gender(fr_split[3]))
	{
//		std::cout << "wrong gender in " << to.size() + count << " line\n";
		count++;
		return  ;
	}
}

void Employer::print_empl(const Employer &empl)
{
	std::cout << "ID: " << empl._id << "\n";
	std::cout << "Name: " << empl._name << "\n";
	std::cout << "Year: " << empl._year << "\n";
	std::cout << "SEX: " << empl._gender << "\n";
}

Employers::Employers()  {}

Employers::Employers(const std::string &path_to_file_r) :
		_path_to_file_r(path_to_file_r){}

Employers::Employers(const std::vector<Employer> &emplrs) :
		_emplrs(emplrs) {}

Employers::Employers(const std::vector<Employer> &emplrs,
					 const std::string &path_to_file_r) :
		_emplrs(emplrs),
		_path_to_file_r(path_to_file_r)
{
	_in.open(path_to_file_r);
	if (!_in)
		std::cout << "Wrong input file";
}

Employers::Employers(const std::vector<Employer> &emplrs,
					 const std::string &path_to_file_r,
					 const std::string &path_to_file_w) :
		_emplrs(emplrs),
		_path_to_file_r(path_to_file_r), _path_to_file_w(path_to_file_w)
{
	_in.open(path_to_file_r);
	if (!_in)
		std::cout << "Wrong input file";
	_out.open(path_to_file_w);
	if (!_out)
		std::cout << "Wrong output file";
}

void Employers::print_emplrs()
{
	std::streambuf  *coutbuf = std::cout.rdbuf();
	if (_path_to_file_w.length())
		std::cout.rdbuf(_out.rdbuf());

	for (auto &n : _emplrs)
		Employer::print_empl(n);

	std::cout.rdbuf(coutbuf);
}

void Employers::add_node(std::vector<Employer> &to, const std::string &from)
{
	std::vector<std::string>	fr_split;
	Employer		new_empl;
	static int 		count = 1;

	fr_split = split(from, ';');
	if (fr_split.size() != 5)
	{
		std::cout << "wrong number of arguments in " << to.size() + count << " line\n";
		count++;
		return ;
	}
	new_empl.set_id(stoi(fr_split[0]));
	new_empl.set_name(fr_split[1]);
	new_empl.set_year(stoi(fr_split[2]));
	if(new_empl.set_gender(fr_split[3]))
	{
		std::cout << "wrong gender in " << to.size() + count << " line\n";
		count++;
		return  ;
	}
	to.push_back(new_empl);
}

int check_vector_csv(std::vector<std::string> &vec)
{
	std::vector<std::string> gen = {"MALE", "FEMALE", "HELICOPTER"};
	if (vec.size() != 5)
		return 0;
	if (vec[3] != gen[1] && vec[3] != gen[2] && vec[3] != gen[0])
		return 0;
	return 1;
}

void Employers::add_emplrs()
{
	std::string			s;
	std::vector<std::string>	fr_split;


	while (std::getline(_in, s))
	{
		fr_split = split(s, ';');
		if (!check_vector_csv(fr_split))
			continue;
		Employer			empl(s);
		_emplrs.push_back(empl);
	}
}


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
