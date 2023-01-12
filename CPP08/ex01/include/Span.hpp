/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:54:12 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/16 16:40:01 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <cstdlib>
#include <time.h>

class Span {

private:
	
		std::vector<int> _spanVector;
		unsigned int	_vectorCapacity;
		
public:

	Span();
	Span( unsigned int n );
	Span( Span const & src );
	~Span();
	
	Span & operator=( Span const & rhs );
	int operator[]( unsigned int index ) const ;

	void addNumber ( int toBeAdded );
	void addNumbers( int toBeAdded );
	void addRandomNumbers( void );

	unsigned int shortestSpan ( void ) ;
	unsigned int longestSpan ( void ) ;

	void printVector( void ) ;

};

#endif