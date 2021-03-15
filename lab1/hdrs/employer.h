//
// Created by fhideous on 05.03.2021.
//

#ifndef CPP_LAB_EMPLOYER_H
#define CPP_LAB_EMPLOYER_H

class Employer
{
public:
	Employer();
	Employer(const std::string &);
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

#endif //CPP_LAB_EMPLOYER_H
