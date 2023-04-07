#include "./include/RPN.hpp"

int main ( int ac, char** av ) {
	(void)av;

	if (ac != 2)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return 1;
	}

	try {

		std::string args = av[1];

		RPN rpn(args);


		std::cout << rpn.calculate() << std::endl;

	}
	catch (std::exception & e) {

		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}