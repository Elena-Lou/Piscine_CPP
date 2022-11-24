/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:11:28 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/24 14:38:05 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int const Fixed::_bitsNb = 8;

Fixed::Fixed ( void ) : _fixedPoint(0) {

	std::cout << "Default Constructor called" << std::endl;
	return ;	
}

Fixed::Fixed ( Fixed const & src ) {

	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

int Fixed::getRawBits ( void ) const {
	
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPoint;
}

Fixed &	Fixed::operator=( Fixed const & rhs ) {

	std::cout << "Copy assignement operator called" << std::endl;
	
	if (this != &rhs)
	{
		this->_fixedPoint = rhs.getRawBits();
	}
	return *this;
}

Fixed::~Fixed ( void ) {
	
	std::cout << "Destructor called" << std::endl;
	return ;
}