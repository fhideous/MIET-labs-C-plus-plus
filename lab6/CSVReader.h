#ifndef CPP_LAB4_CSVREADER_H
#define CPP_LAB4_CSVREADER_H

#include "AbstractReader.h"
#include "CsvException.h"
class CSVReader: public AbstractReader
{
public:
    CSVReader(std::string &path) : AbstractReader(path)
	{
		open_path(path);
	}
	void 		fd_close();
	void		open_path(std::string &path);
    virtual bool 		read(Employer&) override;
//	std::vector<Employer> read_all();
    bool		is_open() const override;


    /*
     * overloads
     */
	friend CSVReader& operator >> (CSVReader &in, Employer &empl);
	operator bool();
};
#endif
