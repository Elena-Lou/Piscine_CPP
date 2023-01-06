/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Arg.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:53:04 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/06 17:34:54 by elouisia         ###   ########.fr       */
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
	}
	return *this;
}

void Arg::setValue ( char* value ) {
	
	this->_value = value;
}

void Arg::convertToLD ( void ) {

	std::istringstream input(this->_value);
	input >> this->_ldValue;
}

void Arg::printValue ( void ) {
	
	this->convertToLD();
	std::cout << "char : " << static_cast<char>(this->_ldValue) << std::endl;
	std::cout << "int : " << static_cast<int>(this->_ldValue) << std::endl;
	std::cout << "float : " << static_cast<float>(this->_ldValue) << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(this->_ldValue) << std::endl;
}

std::string Arg::getValue ( void ) const {

	return this->_value;
}

int	Arg::whatIsYourType ( void ) const {
	
	std::size_t	found;
	
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
	
	switch (this->whatIsYourType()) {
		case INT:
			std::cout << "I am an INT" << std::endl;
			// this->_intValue = std::stoi(this->_value);
			break ; 
		
		case FLOAT:
			std::cout << "I am a FLOAT" << std::endl;
			// this->_floatValue = std::stof(this->_value);
			break ;

		case DOUBLE:
			std::cout << "I am a DOUBLE" << std::endl;
			// this->_doubleValue = std::stod(this->_value);
			break ;

		case CHAR:
			std::cout << "I am a CHAR" << std::endl;
			// this->_charValue = this->_value[0];			
			break ;

		default:
			std::cout << "I am a FAILURE" << std::endl;
			
	}
}