//
// Created by fhideous on 16.03.2021.
//

//#include "../hdrs/employers.h"
#include "employers.h"

#ifndef CPP_LAB_OUT_DATA_H
#define CPP_LAB_OUT_DATA_H

class	OutEmplrs
{
public:

	OutEmplrs(const std::vector<Employer> &);
	OutEmplrs(const std::string &, const std::vector<Employer> &);
	void set_path_w(const std::string &path_w) {
        _out.open(path_w,  std::ios_base::app);
		if (!_out)
			std::cout << "Wrong output file";
		_path_to_file_w = path_w;
	}
	void print_data();
    void set_data(const std::vector<Employer> &empls) {_data = empls;}

private:
	std::ofstream				_out;
	std::vector<Employer>		_data;
	std::string					_path_to_file_w;
};


#endif //CPP_LAB_OUT_DATA_H
