#include "./include/BitcoinExchange.hpp"

/*
Data.csv -> map

	1. faire programme qui prend en param la date et 
		qui ressort la valeur du bitcoin a cette date
	
	2. faire un programme qui prend en param un fichier input.txt	
		et qui ressort les valeurs du bitcoin à toutes les dates listées dans le fichier
	
	3. faire un programme qui prend en param un fichier input.txt	
		et qui ressort la valeur du portefeuille aux dates listées
	
	TIPS :

	- map.lower_bound (std::string date)
	- map.insert(std::make_pair("key", "value"));

	WHAT TO DO NEXT :

	- methods
	- insert in the map
*/

int main ( int ac, char **av ) {

	(void)av;
	if (ac != 2)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return 1;
	}

	std::ifstream	infile;
	std::string		line;
	std::string		str_date;
	double			rate;
	size_t			pos;

	infile.open("data.csv", std::ifstream::in);
	if (!infile)
	{
		std::cerr << "Open Error" << std::endl;
		return -1;
	}
	/* reads the file, while the stream is food, find the position of the 
	comma in the line recovered with getline(). 
	Saves the part of the string which is before the comma in a str_date 
	string, removes the orignal string from the line + the comma.
	Converts the remaining string to a double */
	while(infile.good())
	{
		std::getline(infile, line);
		pos = line.find(",");
		str_date = line.substr(0, pos);
		std::cout << "date : " << str_date << std::endl;
		line.erase(0, pos + 1);
		rate = strtod(line.c_str(), NULL);
		std::cout << "rate : " << rate << std::endl;

	}
	infile.close();

	std::cout << "\n --- test date --- \n" << std::endl;

	const char date1[] = "2011-01-03";
	const char date2[] = "2001-42-42";
	struct tm tm;

	if (strptime(date1, "%Y-%m-%d", &tm))
		std::cout << "valid date" << std::endl;
	if (!strptime(date2, "%Y-%m-%d", &tm))
		std::cout << "not valid date" << std::endl;
	return 0;
}
