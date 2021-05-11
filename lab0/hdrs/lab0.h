//
// Created by fhideous on 01.03.2021.
//

#ifndef MIET_LABS_CPP_LAB0_H
#define MIET_LABS_CPP_LAB0_H

#include <iostream>
#include <vector>
//#include <sstream>
#include <fstream>
#include <ctime>
#include "algorithm"

//enum sex	{MALE, HELICOPTER, FEMALE};

struct node
{
	int			n;
	std::string	name;
	int			year;
	std::string	gender;

	friend bool operator> (const node &d1, const node &d2)
	{
		return (d1.year > d2.year ? true : false);
	}

};




/*
 * splits the str with char
 */
std::vector<std::string> split(const std::string&, char);

/*
 * writing error "first arg" detected in "second arg" line
 */
int		check_errors(int, int);

/*
 * parsing string to struct + push bach in vector; numb curr line to disp errors
 */
int		add_node(std::vector<node> *to, std::string from, int line);

/*
 * print stuff about employer
 */
void	print_node(const node &employer);


#endif //MIET_LABS_CPP_LAB0_H
