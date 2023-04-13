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

/* if the character is a number, it is pushed onto the stack
	When a sign is encountered, the last two elements of the stack (on top of it)
	are removed and the corresponding operation is performed.
	The result is pushed onto the stack

	We check if :
		- the divider is not 0
		- if there is an appropriate number of digits and operands
*/
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
			if (this->_rpn_stack.size() < 2)
				throw RPN::WrongArgumentException();
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
				if (b != 0)
					result = a / b;
				else
					throw RPN::WrongArgumentException();
				break;
			default:
				throw RPN::WrongArgumentException();
				break;
			}
			this->_rpn_stack.push(result);
		} 
	}
	if (this->_rpn_stack.size() != 1)
		throw RPN::WrongArgumentException();

	return result;
}
RPN::~RPN() { 

}

const char* RPN::WrongArgumentException::what( void ) const throw() {

	return ("Error");
}