/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:11:28 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/27 19:40:37 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

int const Fixed::_bitsNb = 8;


/* constructors */

Fixed::Fixed ( void ) : _fixedPoint () {
	
	return ;	
}

Fixed::Fixed ( int const n ) {

	this->_fixedPoint = n * (1 << Fixed::_bitsNb);
	return ;	
}

Fixed::Fixed ( float const fNb ) {

	this->_fixedPoint = roundf(fNb * (float)(1 << Fixed::_bitsNb));
	return ;	
}

Fixed::Fixed ( Fixed const & src ) {

	*this = src;
	return ;
}

/* accessors */

int Fixed::getRawBits ( void ) const {
	
	return this->_fixedPoint;
}

void Fixed::setRawBits ( int const raw ) {
	
	this->_fixedPoint = raw;
}

Fixed &	Fixed::operator=( Fixed const & rhs ) {

	if (this != &rhs)
	{
		this->_fixedPoint = rhs.getRawBits();
	}
	return *this;
}

/* comparison operators */

bool Fixed::operator==( Fixed const & rhs ) {

	return (this->_fixedPoint == rhs._fixedPoint);
}

bool	Fixed::operator!=( Fixed const & rhs ) {

	return (this->_fixedPoint != rhs._fixedPoint);
}

bool Fixed::operator>( Fixed const & rhs ) {

	return (this->_fixedPoint > rhs._fixedPoint);
}

bool Fixed::operator<( Fixed const & rhs ) {

	return (this->_fixedPoint < rhs._fixedPoint);
}

bool Fixed::operator>=( Fixed const & rhs ) {
	
	return (this->_fixedPoint >= rhs._fixedPoint);
}

bool Fixed::operator<=( Fixed const & rhs ) {

	return (this->_fixedPoint <= rhs._fixedPoint);
}

/* arithmetic operators */

Fixed	Fixed::operator+( Fixed const & rhs ) const {

	return (this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-( Fixed const & rhs ) const {

	return (this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*( Fixed const & rhs ) const {

	return (this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/( Fixed const & rhs ) const {

	return (this->toFloat() / rhs.toFloat());
}

/* increment / decrement operators : prefix */

Fixed &	Fixed::operator++( ) {

	this->_fixedPoint +=1;
	return *this;
}

Fixed &	Fixed::operator--( ) {

	this->_fixedPoint -=1;
	return *this;
}

/* increment / decrement operators : postfix */

Fixed	Fixed::operator++( int ) {

	Fixed tmp;
	
	tmp = *this;
	++(*this);
	return tmp;
}

Fixed	Fixed::operator--( int ) {

	Fixed tmp;
	
	tmp = *this;
	--(*this);
	return tmp;
}

/* member functions : conversions */

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


/* static functions : min / max */
Fixed & Fixed::min( Fixed & f1, Fixed & f2) {
	
	if (f1 < f2)
		return f1;
	else
		return f2;
}

Fixed & Fixed::max( Fixed & f1, Fixed & f2) {
	
	if (f1 > f2)
		return f1;
	else
		return f2;
}

const Fixed & Fixed::min( Fixed const & f1, Fixed const & f2) {
	
	if (f1.getRawBits() < f2.getRawBits())
		return f1;
	else
		return f2;
}

const Fixed & Fixed::max( Fixed const & f1, Fixed const & f2) {
	
	if (f1.getRawBits() > f2.getRawBits())
		return f1;
	else
		return f2;
}

/* destructors */

Fixed::~Fixed ( void ) {
	
	return ;
}

/* insertion operator overload to print the converted value */

std::ostream & operator<<( std::ostream & o, Fixed const & rhs) {
	
	o << rhs.toFloat();
	return o;
}
