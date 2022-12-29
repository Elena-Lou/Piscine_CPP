/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Arg.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:53:04 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/29 18:58:00 by elouisia         ###   ########.fr       */
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

std::string Arg::getValue( void ) const {

	return this->_value;
}