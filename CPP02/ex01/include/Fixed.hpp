/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:11:56 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/25 14:14:39 by elouisia         ###   ########.fr       */
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
	Fixed( Fixed const & src); // copy constructor which takes an instance of the current class as param to create a new one.
	Fixed(int const n);
	Fixed(float const fNb);
	~Fixed( void );
	
	Fixed & operator=( Fixed const & rhs ); // assignement operator overload which updates the current instance, it does  not create a new one
	
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream & operator<<( std::ostream & out, Fixed const & rhs);

#endif