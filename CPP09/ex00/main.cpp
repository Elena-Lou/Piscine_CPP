#include "./include/BitcoinExchange.hpp"

int main ( int ac, char **av ) {

	if (ac != 2)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return 1;
	}

	std::ifstream	input;
	std::string 	line;

	input.open(av[1], std::ifstream::in);
	if (!input)
	{
		std::cerr << "Open error" << std::endl;
		return 1;
	}
	while (getline(input, line))
	{
		std::cout << line << std::endl;
	}

	std::cout << "\n --- test date --- \n" << std::endl;

	const char date1[] = "2011-01-03";
	const char date2[] = "2001-42-42";
	struct tm tm;

	if (strptime(date1, "%Y-%m-%d", &tm))
		std::cout << "valid date" << std::endl;
	if (!strptime(date2, "%Y-%m-%d", &tm))
		std::cout << "not valid date" << std::endl;

	input.close();
	return 0;
}