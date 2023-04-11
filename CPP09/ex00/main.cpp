#include "./include/BitcoinExchange.hpp"

int main ( void ) {

	std::cout << "BOUH" << std::endl;

	const char date1[] = "2011-01-03";
	const char date2[] = "2001-42-42";
	struct tm tm;

	if (strptime(date1, "%Y-%m-%d", &tm))
		std::cout << "valid date" << std::endl;
	if (!strptime(date2, "%Y-%m-%d", &tm))
		std::cout << "not valid date" << std::endl;


	return 0;
}