/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Arg.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:53:04 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/10 11:21:56 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Arg.hpp"

/* types scalaires : composé d'un seul type de donnée élémentaire (int Vs structure)
	- check strtod : 
	strtod(str, &end) -> returns str value as a double or 0 if no valid conversion is possible
	end : the first character after the converted number
	
*/

Arg::Arg ( void )  : _charValue(0), _precision(1) {

	// std::cout << "[Arg Class] Constructor" << std::endl;
	return ;
}

Arg::~Arg ( void ) {

	// std::cout << "[Arg Class] Destructor" << std::endl;
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
		this->_charValue = rhs._charValue;
		this->_infinityValue = rhs._infinityValue;
		this->_precision = rhs._precision;
	}
	return *this;
}

void Arg::setValue ( char* value ) {
	
	this->_value = value;
}

std::string Arg::getValue ( void ) const {

	return this->_value;
}

void Arg::printValue ( void ) const {
	
	double convertedInput;
	convertedInput = std::strtod(this->_value.c_str(), NULL);
	
	if (this->_charValue != 0)
	{
		if (!isprint(this->_charValue))
			std::cout << "char : non displayable" << std::endl;
		else 
			std::cout << "char : " << this->_charValue << std::endl;
		std::cout << "int : " << static_cast<int>(this->_charValue) << std::endl;
		std::cout << "float : " << std::fixed << std::setprecision(this->_precision) << static_cast<float>(this->_charValue) << "f" << std::endl;
		std::cout << "double : " << static_cast<double>(this->_charValue) << std::endl;
	}
	else
	{
		if (!isprint(static_cast<char>(convertedInput)))
			std::cout << "char : non displayable" << std::endl;
		else 
			std::cout << "char : " << static_cast<char>(convertedInput) << std::endl;
			
		if (convertedInput <= std::numeric_limits<int>::min() || convertedInput >= std::numeric_limits<int>::max())
			std::cout << "int : impossible "  << std::endl;
		else
			std::cout << "int : " << static_cast<int>(convertedInput) << std::endl;
			
		if (convertedInput <= -std::numeric_limits<float>::max() || convertedInput >= std::numeric_limits<float>::max())
			std::cout << "float : impossible "  << std::endl;
		else
			std::cout << "float : " << std::fixed << std::setprecision(this->_precision) << static_cast<float>(convertedInput) << "f" << std::endl;
		
		if (convertedInput <= -std::numeric_limits<double>::max() || convertedInput >= std::numeric_limits<double>::max())
			std::cout << "double : impossible "  << std::endl;
		else
			std::cout << "double : " << static_cast<double>(convertedInput) << std::endl;
	}
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
	
	else if (this->_infinityValue == NANVAL)
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
		return NANVAL;
	else
		return 0;
	
}

int	Arg::whatIsYourType ( void ) {
	
	std::size_t	found;

	if (this->_value.size() == 1 && !isdigit(this->_value[0]))
	{
		this->_charValue = this->_value[0];
		return CHAR;
	}
	else
	{
		if (this->_value[0] == '-' && !isdigit(this->_value[1]))
			return FAILURE;
		for (unsigned int i = 0; i < this->_value.size(); i++)
		{
			if (!isdigit(this->_value[i]))
			{
				if (this->_value[i] != '.' && this->_value[i] != 'f' && this->_value[i] != '-')
					return FAILURE;
				found = this->_value.find('.');
				if (found != std::string::npos)
				{
					this->_precision = this->_value.size() - (found + 1);
					found = this->_value.find('.', found + 1);
					if (found != std::string::npos)
						return FAILURE;
					else if (this->_value[i + 1] && !isdigit(this->_value[i + 1]))
						return FAILURE;
					found = this->_value.find('f');
					if (found != std::string::npos)
					{
						if (found == this->_value.size() - 1)
							this->_precision--;
					}
				}
			}
		}
		return INT;
	}
}

void Arg::typeChecker ( void ) {

	double convertedInput;
	convertedInput = std::strtod(this->_value.c_str(), NULL);
	if (errno == ERANGE)
	{
		std::cout << "char : impossible"  << std::endl;
		std::cout << "int : impossible"  << std::endl;
		std::cout << "float : impossible"<< std::endl;
		std::cout << "double : impossible" << std::endl;
		return ;
	}
	
	this->_infinityValue = this->infinityCheck();
	if (this->_infinityValue != 0)
	{
		this->printInfinity();
		return ;
	}
	if (this->whatIsYourType() == FAILURE)
	{
		std::cerr << "Invalid Argument" << std::endl;
		return ;
	}

	printValue();
}
