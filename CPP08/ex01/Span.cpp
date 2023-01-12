/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:53:49 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/12 18:23:55 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span ( void ) : _spanVector(0)  {
	
	std::cout << "[Span] Default Constructor" << std::endl;
	std::cout << "vector size : " << _spanVector.size() << std::endl;
}

Span::Span ( unsigned int n ) : _spanVector(n) {

	std::cout << "[Span] Constructor" << std::endl;
	std::cout << "vector size : " << _spanVector.size() << std::endl;
}

Span::Span ( Span const & src ) {
	
	*this = src;	
}

Span & Span::operator=( Span const & rhs ) {

	if (this != &rhs)
	{
		this->_spanVector = rhs._spanVector;
	}
	return *this;
}

void Span::addNumber ( void ) {

	std::cout << "this->_spanVector.mx_size: " << this->_spanVector.max_size() << std::endl;
	
}

// unsigned int Span::shortestSpan ( void ) const {
	
// }

// unsigned int Span::longestSpan ( void ) const {
	
// }

Span::~Span ( void ) {
	
	std::cout << "[Span] Destructor" << std::endl;
}