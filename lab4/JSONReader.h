//
// Created by fhideous on 04.04.2021.
//

#ifndef CPP_LAB4_JSONREADER_H
#define CPP_LAB4_JSONREADER_H

#include "AbstractReader.h"

class JSONReader: public AbstractReader {
public:
	explicit JSONReader(std::string &path):
		AbstractReader(path){}
	Employer	read();

};


#endif //CPP_LAB4_JSONREADER_H
