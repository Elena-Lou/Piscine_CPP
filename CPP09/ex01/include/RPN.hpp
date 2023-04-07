#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <exception>

class RPN {

private:

	std::stack<int> _rpn_stack;
	std::string 	_args;
	RPN();

public:

	RPN( std::string args );
	RPN( RPN const & src );
	~RPN();

	RPN & operator=( RPN const & rhs );

	std::string getArgs ( void );
	
	class WrongArgumentException : public std::exception
	{
		public:

			const char* what( void ) const throw();
	};
};

#endif