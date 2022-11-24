/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:11:28 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/25 14:48:36 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

int const Fixed::_bitsNb = 8;

Fixed::Fixed ( void ) : _fixedPoint(0) {

	std::cout << "Default constructor called" << std::endl;
	return ;	
}

Fixed::Fixed ( int const n ) {

	std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = n * (1 << Fixed::_bitsNb);
	return ;	
}

Fixed::Fixed ( float const fNb ) {

	std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = roundf(fNb * (float)(1 << Fixed::_bitsNb));
	return ;	
}

Fixed::Fixed ( Fixed const & src ) {

	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

int Fixed::getRawBits ( void ) const {
	
	return this->_fixedPoint;
}

void Fixed::setRawBits ( int const raw ) {
	
	this->_fixedPoint = raw;
}

Fixed &	Fixed::operator=( Fixed const & rhs ) {

	std::cout << "Copy assignement operator called" << std::endl;
	
	if (this != &rhs)
	{
		this->_fixedPoint = rhs.getRawBits();
	}
	return *this;
}

float Fixed::toFloat ( void ) const {

	float nbFloat;
	
	nbFloat = (float)this->_fixedPoint / (float)(1 << Fixed::_bitsNb);
	return nbFloat;
}

int Fixed::toInt ( void ) const {

	int nbInt;
	
	nbInt = this->_fixedPoint >> Fixed::_bitsNb;
	return nbInt;
}

Fixed::~Fixed ( void ) {
	
	std::cout << "Destructor called" << std::endl;
	return ;
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs) {
	
	o << rhs.toFloat();
	return o;
}
