//
// Created by fhideous on 04.04.2021.
//

#ifndef CPP_LAB4_JSONREADER_H
#define CPP_LAB4_JSONREADER_H

#include "AbstractReader.h"

class JSONReader: public AbstractReader {
public:
	explicit JSONReader(std::string &path): AbstractReader(path)
	{
		open_path(path);
	}
	void 		fd_close();
	void		open_path(std::string &path);
	bool 		read(Employer &);
	std::vector<Employer> read_all();
	bool		is_open() const;

private:
	nlohmann::json json;
};


#endif //CPP_LAB4_JSONREADER_H
