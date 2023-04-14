#include "./include/BitcoinExchange.hpp"

/*
Data.csv ==> map

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

	BcExchange btc;

	btc.initialiseDB();
	// btc.getDatesInputFile(av[1]);
	btc.getBTCValues(av[1]);
	

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
