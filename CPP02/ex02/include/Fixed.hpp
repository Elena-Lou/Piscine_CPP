/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:11:56 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/27 19:40:55 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	
	int					_fixedPoint;
	static const int	_bitsNb;

public:

	Fixed( void );
	Fixed( Fixed const & src); // copy constructor
	Fixed(int const n);
	Fixed(float const fNb);
	~Fixed( void );
	
	Fixed & operator=( Fixed const & rhs );

	/* comparison operators */
	bool operator>( Fixed const & rhs );
	bool operator<( Fixed const & rhs );
	bool operator>=( Fixed const & rhs );
	bool operator<=( Fixed const & rhs );
	bool operator==( Fixed const & rhs );
	bool operator!=( Fixed const & rhs );
	
	/* arithmetic operators */
	Fixed operator+( Fixed const & rhs ) const;
	Fixed operator-( Fixed const & rhs ) const;
	Fixed operator*( Fixed const & rhs ) const;
	Fixed operator/( Fixed const & rhs ) const;

	/* increment / decrement operators */
	Fixed & operator++( void ); // prefix
	Fixed & operator--( void ); // prefix
	Fixed operator++( int ); // postfix
	Fixed operator--( int ); // postfix
	
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	
	float	toFloat( void ) const;
	int		toInt( void ) const;

	static Fixed & min( Fixed & f1, Fixed & f2);
	static Fixed & max( Fixed & f1, Fixed & f2);
	
	static const Fixed & min( Fixed const & f1, Fixed const & f2); 
	static const Fixed & max( Fixed const & f1, Fixed const & f2); 

};

std::ostream & operator<<( std::ostream & out, Fixed const & rhs);

#endif