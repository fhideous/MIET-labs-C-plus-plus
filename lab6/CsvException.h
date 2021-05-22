#ifndef CPP_LAB_CSVEXCEPTION_H
#define CPP_LAB_CSVEXCEPTION_H

#include "lab.h"

class CsvException: public std::exception{
private:
	 std:: string what_m;
public:
	CsvException(std::string error)
	{
		what_m = error;
	}
	virtual const char* what() const throw()
	{return what_m.c_str();}
};


#endif
