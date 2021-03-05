//
// Created by fhideous on 05.03.2021.
//

#ifndef CPP_LAB_EMPLOYER_H
#define CPP_LAB_EMPLOYER_H

class Employer
{
public:
	Employer();
	Employer(int id, const std::string &, int, const std::string &);
	~Employer();

	void set_id(int id) { _id = id;}
	void set_name(const std::string &name) { _name = name;}
	void set_year(int year) { _year = year;}
	int set_gender(const std::string &gender) {
		if (gender == "MALE" ||
			gender == "HELICOPTER" ||
			gender ==	"FEMALE")
			_gender = gender;
		else
			return(1);
		return(0);
	}
	static void print_empl(const Employer &empl);

private:
	int					_id;
	std::string			_name;
	int 				_year;
	std::string			_gender;

};

Employer::Employer() : _id(0), _name("-"),
					_year(0), _gender("") {}

Employer::~Employer() {}

Employer::Employer(int id, const std::string &name, int year,
				   const std::string &gender) :
		_id(id), _name(name),
		_year(year), _gender(gender) {}

void Employer::print_empl(const Employer &empl)
{
	std::cout << "ID: " << empl._id << "\n";
	std::cout << "Name: " << empl._name << "\n";
	std::cout << "Year: " << empl._year << "\n";
	std::cout << "SEX: " << empl._gender << "\n";
}

#endif //CPP_LAB_EMPLOYER_H
