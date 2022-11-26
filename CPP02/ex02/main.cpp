/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:13:12 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/27 19:10:43 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c;

	c = b;

	std::cout << "a: " << a << std::endl;
	std::cout << "a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	
	std::cout << " \n--------------------\n" << std::endl;
	
	std::cout << "c: " << c << std::endl;
	std::cout << "c: " << ++c << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "c: " << c++ << std::endl;
	std::cout << "c: " << c << std::endl;

	std::cout << " \n--------------------\n" << std::endl;

	std::cout << "max a c: " << Fixed::max( a, c ) << std::endl;
	std::cout << "min c a: " << Fixed::min( c, a ) << std::endl;
	std::cout << "max c b: " << Fixed::max( c, b ) << std::endl;
	std::cout << "min c b: " << Fixed::min( c, b ) << std::endl;

	std::cout << " \n--------------------\n" << std::endl;
	
	std::cout << "max a b: " << Fixed::max( a, b ) << std::endl;
	std::cout << "min a b: " << Fixed::min( a, b ) << std::endl;
	
	std::cout << " \n--------------------\n" << std::endl;
	
	
	std::cout << "a: " << a << std::endl;
	std::cout << "a: " << --a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a: " << a-- << std::endl;
	std::cout << "a: " << a << std::endl;
	

	return 0;
}