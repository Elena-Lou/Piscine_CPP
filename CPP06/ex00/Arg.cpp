/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Arg.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:53:04 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/06 15:39:55 by elouisia         ###   ########.fr       */
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

std::string Arg::getValue ( void ) const {

	return this->_value;
}

int	Arg::whatIsYourType ( void ) {
	
	std::size_t	found;
	
	if (this->_value.size() == 1 && !isdigit(this->_value[0]))
	{
		std::cerr << "I am a CHAR" << std::endl;
		return CHAR;
	}
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
					{
						std::cerr << "I am a FAILURE" << std::endl;
						return FAILURE;	
					}
					else if (!isdigit(this->_value[i + 1]))
					{
						std::cerr << "I am a FAILURE" << std::endl;
						return FAILURE;
					}
					found = this->_value.find('f');
					if (found != std::string::npos)
					{
						std::cerr << "float condition - found pos : " << found << " - this->_value.size() : " << this->_value.size() << std::endl;
						if (found == this->_value.size() - 1)
						{
							std::cerr << "I am a FLOAT" << std::endl;
							return FLOAT;
						}
						else
						{
							std::cerr << "I am a FAILURE" << std::endl;
							return FAILURE;
						}
					}
					else
						{
							std::cerr << "I am a DOUBLE" << std::endl;
							return DOUBLE;
						}
				}
				std::cerr << "I am a FAILURE" << std::endl;
				return FAILURE;	
			}
		}
		std::cerr << "I am an INT" << std::endl;
		return INT;
	}
}