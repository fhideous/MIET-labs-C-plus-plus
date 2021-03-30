//
// Created by fhideous on 05.03.2021.
//
//#include "../hdrs/lab.h"
#include "lab.h"

#ifndef CPP_LAB_EMPLOYER_H
#define CPP_LAB_EMPLOYER_H

class Employer
{
public:
	Employer();
	Employer(const std::string &);
    Employer(int, const std::string &, int, const std::string &);
    Employer(const Employer &);                                // конструктор копирования
    Employer(Employer &&);                                     // конструктор перемещения получает rvalue reference
    ~Employer();


    void operator=(const Employer &obj);      //присваивание с копированием
    void operator=(Employer && obj);                  //оператор присваивания без копирования

    void set_id(int id) { check_valid_id(id);}
	void set_name(const std::string &name) { _name = name;}
	void set_year(int year) { _year = year;}
	int set_gender(const std::string &gender)  const{
		if (gender == "MALE" ||
			gender == "HELICOPTER" ||
			gender ==	"FEMALE")
			return(0);
		return(1);
	}
    std::string     get_name() { return _name; }
    int             get_id() {return _id;}
    std::string     get_gender() {return _gender;}
    int             get_year() {return _year;}
	void print_empl();
    int check_valid_id(int);

private:
    int					_id ;
    std::string			_name;
    int 				_year ;
    std::string			_gender;

};

#endif //CPP_LAB_EMPLOYER_H
