/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:11:56 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/24 14:43:50 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	
	int	_fixedPoint;
	static const int	_bitsNb;
	
public:

	Fixed( void );
	Fixed( Fixed const & src); // copy constructor which takes an instance of the current class as param to create a new one.
	~Fixed( void );
	
	Fixed & operator=( Fixed const & rhs ); // assignement operator overload which updates the current instance, it does  not create a new one
	
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif