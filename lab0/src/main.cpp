
#include "../hdrs/lab0.h"

/*
 * file .csv must end with one empty line
 */


void print_file(const std::vector<node> &file)
{
	std :: cout << "All employers: \n";
	std :: cout << "==========================\n";
	for (auto &n : file)
		print_node(n);
	std :: cout << "==========================\n";
	std :: cout << "end of list\n";
}

void print_file_if(const std::vector<node> &file)
{
	time_t now = time(0);

	tm *date = localtime(&now);
	std :: cout << "All employers older then 31: \n";
	for (auto &n : file)
		if (date->tm_year + 1900 - n.year > 31)
			print_node(n);
	std::cout << "That was all employers\n";
}

int read_file(std::ifstream &file, std::vector<node> *csv)
{
	std::string			s;
	int					count_line = 1;

	while (std::getline(file,s))
	{
		if(add_node(csv, s, count_line))
			return (1);
		count_line++;
	}
	return (0);
}

void sort_by_year(std::vector<node> &csv)
{
	std::sort(csv.begin(), csv.end(),
		   [](const node& c1, const node& c2){
		return c1.year > c2.year; });
}

void write_to_file(const std::vector<node> &csv,  std::string &file_path, void print(const std::vector<node> &))
{
	std::ofstream out(file_path);
	std::streambuf *coutbuf = std::cout.rdbuf();
	std::cout.rdbuf(out.rdbuf());

	print(csv);
	std::cout.rdbuf(coutbuf);
}

int main()
{
	std::ifstream		file;
	std::vector<node>	csv;

	file.open("../asf.csv");
	if(!file)
		check_errors(1, 0);
	else
		file.close();

	file.open("../csv.csv");
	if(!file)
		return (check_errors(1, 0));

	if (read_file(file, &csv))
		return (1);

	std::string file_0 = "../0";
	std::string file_1 = "../1";
	std::string file_2 = "../2";

//	print_file(csv);
	write_to_file(csv, file_0, print_file);
	write_to_file(csv, file_1, print_file_if);
	sort_by_year(csv);
	write_to_file(csv, file_2, print_file);

	file.close();
    return 0;
}
