/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:53:49 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/16 16:42:10 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span ( void ) : _spanVector(0), _vectorCapacity(0)  {
	
	std::cout << "[Span] Default Constructor" << std::endl;
}

Span::Span ( unsigned int n ) : _spanVector(0), _vectorCapacity(n) {

	std::cout << "[Span] Constructor" << std::endl;
}

Span::Span ( Span const & src ) {
	
	*this = src;	
}

Span & Span::operator=( Span const & rhs ) {

	if (this != &rhs)
	{
		this->_spanVector = rhs._spanVector;
		this->_vectorCapacity = rhs._vectorCapacity;
	}
	return *this;
}

int Span::operator[]( unsigned int index ) const {

	if ( index >= this->_vectorCapacity)
		throw std::length_error("Invalid Index");
	return this->_spanVector[index];
}

void Span::addNumber ( int toBeAdded ) {

	if (this->_vectorCapacity == 0 || this->_spanVector.size() == this->_vectorCapacity)
		throw std::length_error("Can't access memory space");
	this->_spanVector.push_back(toBeAdded);
	std::sort(this->_spanVector.begin(), this->_spanVector.end());
	this->printVector();

}

void Span::addNumbers ( int toBeAdded ) {

	if (this->_vectorCapacity == 0 || this->_spanVector.size() == this->_vectorCapacity)
		throw std::length_error("can't access memory space");
	this->_spanVector.insert(this->_spanVector.begin(), this->_vectorCapacity, toBeAdded);
	std::sort(this->_spanVector.begin(), this->_spanVector.end());
	this->printVector();
}

void Span::addRandomNumbers ( void ) {

	if (this->_vectorCapacity == 0 || this->_spanVector.size() == this->_vectorCapacity)
		throw std::length_error("can't access memory space");
	for (unsigned int i = 0; i < this->_vectorCapacity; i++)
	{
		int random = std::rand() % 500;
		this->_spanVector.push_back(random);
	}
	std::sort(this->_spanVector.begin(), this->_spanVector.end());
	this->printVector();
}

unsigned int Span::shortestSpan ( void ) {
	
	if (this->_spanVector.size() <= 1)
		throw std::length_error("Invalid size");
	int minDist = this->longestSpan();
	int tmp;
	for (std::vector<int>::iterator ite = this->_spanVector.begin(); ite != this->_spanVector.end() - 1; ite++)
	{
		tmp = *(ite + 1) - *ite;
		if (tmp < minDist)
		minDist = tmp;
	}
	return minDist;
	
}

unsigned int Span::longestSpan ( void ) {

	if (this->_spanVector.size() <= 1)
		throw std::length_error("Invalid size");
	int min = *std::min_element(this->_spanVector.begin(), this->_spanVector.end());
	int max = *std::max_element(this->_spanVector.begin(), this->_spanVector.end());
	return (max - min);
}

Span::~Span ( void ) {
	
	std::cout << "[Span] Destructor" << std::endl;
}

void Span::printVector ( void ) {
	
	for (std::vector<int>::iterator it = this->_spanVector.begin(); it != this->_spanVector.end(); it++)
	{
		std::cout << "[" << *it << "]" ;
	}
	std:: cout << std::endl;
}