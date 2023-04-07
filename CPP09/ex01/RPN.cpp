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

RPN::~RPN() { 

	this->_rpn_stack.empty();
	std::cout << "[RPN] Destructor" << std::endl;
}

const char* RPN::WrongArgumentException::what( void ) const throw() {

	return ("Error");
}