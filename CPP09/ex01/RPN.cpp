#include "./include/RPN.hpp"

RPN::RPN() {

	std::cout << "[RPN] Default Constructor" << std::endl;
}

RPN::RPN( std::string args ) : _args(args) {}


RPN::RPN( RPN const & src ) {

	*this = src;
	return;
}

RPN & RPN::operator=( RPN const & rhs ) {

	if (this != &rhs)
	{
		this->_args = rhs._args;
		this->_rpn_stack = rhs._rpn_stack;
	}
	return *this;
}

std::string RPN::getArgs ( void ) {

	return this->_args;
}

int RPN::calculate ( void ) {

	int result;
	std::string input = this->_args;

	for (unsigned int i = 0; i < input.size(); i++)
	{
		if (std::isdigit(input[i]))
			this->_rpn_stack.push(input[i] - 48);
		else if (input[i] == ' ')
			continue ;
		else
		{
			int b = this->_rpn_stack.top();
			this->_rpn_stack.pop();
			int a = this->_rpn_stack.top();
			this->_rpn_stack.pop();

			switch (input[i]) {
			case '+':
				result = a + b;
				break;
			case '-':
				result = a - b;
				break;
			case '*':
				result = a * b;
				break;
			case '/':
				result = a / b;
				break;
			default:
				throw RPN::WrongArgumentException();
				break;
			}
			this->_rpn_stack.push(result);
		} 
	}
	return result;
}
RPN::~RPN() { 

	this->_rpn_stack.empty();
	std::cout << "[RPN] Destructor" << std::endl;
}

const char* RPN::WrongArgumentException::what( void ) const throw() {

	return ("Error");
}