/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:54:12 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/12 18:11:49 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span {

private:
	
		std::vector<int> _spanVector;
		
public:

	Span();
	Span( unsigned int n );
	Span( Span const & src );
	~Span();
	
	Span & operator=( Span const & rhs );

	void addNumber ( void );
	unsigned int shortestSpan ( void ) const ;
	unsigned int longestSpan ( void ) const ;

};

#endif