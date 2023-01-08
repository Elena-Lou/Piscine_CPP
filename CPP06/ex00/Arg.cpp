/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Arg.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:53:04 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/08 18:59:36 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Arg.hpp"

Arg::Arg ( void ) {

	std::cout << "[Arg Class] Constructor" << std::endl;
	return ;
}

Arg::~Arg ( void ) {

	std::cout << "[Arg Class] Destructor" << std::endl;
	return ;
}

Arg::Arg ( Arg const & src ) {
	
	*this = src;
	return ;
}

Arg & Arg::operator=( Arg const & rhs ) {

	if (this != &rhs)
	{
		this->_value = rhs._value;
		this->_intValue = rhs._intValue;
		this->_floatValue = rhs._floatValue;
		this->_doubleValue = rhs._doubleValue;
		this->_infinityValue = rhs._infinityValue;
	}
	return *this;
}

void Arg::setValue ( char* value ) {
	
	this->_value = value;
}

std::string Arg::getValue ( void ) const {

	return this->_value;
}

void Arg::printFromInt ( void ) const {
	
	if (!isprint(static_cast<char>(this->_intValue)))
	{
		std::cout << "char : non displayable" << std::endl;
	}
	else 
		std::cout << "char : " << static_cast<char>(this->_intValue) << std::endl;
	std::cout << "int : " << static_cast<int>(this->_intValue) << std::endl;
	std::cout << "float : " << static_cast<float>(this->_intValue) << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(this->_intValue) << std::endl;
}

void Arg::printFromFloat ( void ) const {
	
	if (!isprint(static_cast<char>(this->_floatValue)))
	{
		std::cout << "char : non displayable" << std::endl;
	}
	else 
	std::cout << "char : " << static_cast<char>(this->_floatValue) << std::endl;
	std::cout << "int : " << static_cast<int>(this->_floatValue) << std::endl;
	std::cout << "float : " << this->_floatValue << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(this->_floatValue) << std::endl;
}

void Arg::printFromDouble ( void ) const {
	
	if (!isprint(static_cast<char>(this->_doubleValue)))
	{
		std::cout << "char : non displayable" << std::endl;
	}
	else 
	std::cout << "char : " << static_cast<char>(this->_doubleValue) << std::endl;
	std::cout << "int : " << static_cast<int>(this->_doubleValue) << std::endl;
	std::cout << "float : " << static_cast<float>(this->_doubleValue) << "f" << std::endl;
	std::cout << "double : " << this->_doubleValue << std::endl;
}

void Arg::printFromChar ( void ) const {
	
	std::cout << "char : " << this->_charValue << std::endl;
	std::cout << "int : " << static_cast<int>(this->_charValue) << std::endl;
	std::cout << "float : " << static_cast<float>(this->_charValue) << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(this->_charValue) << std::endl;
}

void Arg::printInfinity ( void ) const {

	if (this->_infinityValue == NEGINF)
	{
		std::cout << "char : impossible "  << std::endl;
		std::cout << "int : impossible "  << std::endl;
		std::cout << "float : -inff" << std::endl;
		std::cout << "double : -inf" << std::endl;
	}
	
	else if (this->_infinityValue == POSINF)
	{
		std::cout << "char : impossible "  << std::endl;
		std::cout << "int : impossible "  << std::endl;
		std::cout << "float : inff" << std::endl;
		std::cout << "double : inf" << std::endl;
	}
	
	else if (this->_infinityValue == NAN)
	{
		std::cout << "char : impossible "  << std::endl;
		std::cout << "int : impossible "  << std::endl;
		std::cout << "float : nanf" << std::endl;
		std::cout << "double : nan" << std::endl;
	}
	
}

int Arg::infinityCheck ( void ) const {
	
	if (this->_value == "-inf" || this->_value == "-inff")
		return NEGINF;
	else if (this->_value == "inf" || this->_value == "inff")
		return POSINF;
	else if (this->_value == "nan" || this->_value == "nanf")
		return NAN;
	else
		return 0;
	
}

int	Arg::whatIsYourType ( void ) {
	
	std::size_t	found;

	this->_infinityValue = this->infinityCheck();
	if (this->_infinityValue != 0)
	{
		this->printInfinity();
		return FAILURE;
	}
	
	if (this->_value.size() == 1 && !isdigit(this->_value[0]))
		return CHAR;
	else
	{
		if (this->_value[0] == '-' && !isdigit(this->_value[1]))
			return FAILURE;
		for (unsigned int i = 1; i < this->_value.size(); i++)
		{
			if (!isdigit(this->_value[i]))
			{
				found = this->_value.find('.');
				if (found != std::string::npos)
				{
					found = this->_value.find('.', found + 1);
					if (found != std::string::npos)
						return FAILURE;
					else if (!isdigit(this->_value[i + 1]))
						return FAILURE;
					found = this->_value.find('f');
					if (found != std::string::npos)
					{
						if (found == this->_value.size() - 1)
							return FLOAT;
						else
							return FAILURE;
					}
					else
						return DOUBLE;
				}
				return FAILURE;	
			}
		}
		return INT;
	}
}

void Arg::typeSwitcher ( void ) {

	std::istringstream input(this->_value);
	
	switch (this->whatIsYourType()) {
		case INT:
			std::cerr << "I am an INT" << std::endl;
			input >> this->_intValue;
			this->printFromInt();
			break ; 
		
		case FLOAT:
			std::cerr << "I am a FLOAT" << std::endl;
			input >> this->_floatValue;
			this->printFromFloat();
			break ;

		case DOUBLE:
			std::cerr << "I am a DOUBLE" << std::endl;
			input >> this->_doubleValue;
			this->printFromDouble();
			break ;

		case CHAR:
			std::cerr << "I am a CHAR" << std::endl;
			this->_charValue = this->_value[0];
			this->printFromChar();		
			break ;

		default:
			std::cout << "I am a FAILURE" << std::endl;
			
	}
}