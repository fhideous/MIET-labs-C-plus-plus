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

//	Employer(const std::string &, int, const std::string &);
    Employer(const Employer &) = delete;                      // конструктор копирования
    Employer(Employer &&);                                     // конструктор перемещения получает rvalue reference
    ~Employer();
//    void operator= (const Employer &obj);      //присваивание с копированием

    void operator= (Employer && obj);                  //оператор присваивания без копирования
    void set_name(const std::string &name) { _name = name;}

    void set_year(int year) { _year = year;}
	void set_id(int id) { _id = id;}
    bool set_gender(const std::string &gender) { _gender = gender;}
    virtual	std::string repr() const;
    std::string     get_name() const {return _name;}
    std::string     get_gender() const {return _gender;}
    int             get_year() const {return _year;}
    static int      GET_ID() {return ++s_id;}
    void 			print_empl() const;
    int				get_id() const {return _id;}
    void            id_reset() {s_id = 0;}

    /*
     * overloads
     */
	friend std::ostream& operator<< (std::ostream &out, const Employer &empl);

protected:
    int					_id ;
    std::string			_name;
    int 				_year ;
    std::string			_gender;

};

#endif //CPP_LAB_EMPLOYER_H
