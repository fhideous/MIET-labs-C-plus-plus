//
// Created by fhideous on 05.03.2021.
//
//#include "../hdrs/lab.h"
#include "lab.h"

#ifndef CPP_LAB_EMPLOYER_H
#define CPP_LAB_EMPLOYER_H

class Employer
{
	static int s_id;
public:
	Employer();
	Employer(const std::vector<std::string> &);
	Employer(int id, const std::vector<std::string> &);

	Employer(const std::string &, const std::string &, const std::string &);
	Employer(const Employer &) = delete;                      // конструктор копирования
	Employer(Employer &&);                                     // конструктор перемещения получает rvalue reference
	~Employer();
	void operator= (const Employer &obj);      //присваивание с копированием


	void operator= (Employer && obj);                  //оператор присваивания без копирования
	void set_name(const std::string &name) { _name = name;}

	void set_year(std::string year) { _year = std::move(year);}
	int set_gender(const std::string &gender)  const{
		if (gender == "MALE" ||
			gender == "HELICOPTER" ||
			gender ==	"FEMALE")
			return(0);
		return(1);
	}
//	virtual	std::string repr() const;
	std::string     get_name() const {return _name;}
	std::string     get_gender() const {return _gender;}
	std::string     get_year() const {return _year;}
	static int      GET_ID() {return s_id++;}
	void 			print_empl() const;
	int				get_id() const {return _id;}

protected:
	int					_id ;
	std::string			_name;
	std::string 		_year ;
	std::string			_gender;

};

#endif