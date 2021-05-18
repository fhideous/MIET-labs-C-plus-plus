//
// Created by fhideous on 16.03.2021.
//

#include "Empl.h"

#ifndef CPP_LAB_OUT_DATA_H
#define CPP_LAB_OUT_DATA_H

class	OutEmplrs
{
public:
	OutEmplrs(const std::string &);
    OutEmplrs(const std::string &, const Employer &);
	bool set_path_w(const std::string &path_w);
    void print_data(const Employer &) const;

private:
	std::ofstream				_out;
	std::string					_path_to_file_w;
};


#endif //CPP_LAB_OUT_DATA_H
