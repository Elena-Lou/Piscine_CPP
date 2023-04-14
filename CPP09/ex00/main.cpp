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
	
	
	return 0;
}
