/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:49:08 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/07 14:24:48 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <string>
#include <iostream>

Brain::Brain ( void ) {
	
	std::cout << "[Brain class] Default Constructor" << std::endl;
	return ;
}

Brain::Brain( Brain const & src ) {

	std::cout << "[Brain class] Copy Constructor" << std::endl;
	*this = src;
	return;	
}

Brain & Brain::operator=( Brain const & rhs ) {

	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = rhs.ideas[i];
		}
	}
	return *this;
}

std::string Brain::getIdea ( int i ) const {

	if (i < 0 || i > 99)
	{
		return ("Invalid index");
	}
	return this->ideas[i];
}

void Brain::setIdeas ( std::string const & ideas ) {
	
	for (int i = 0 ; i < 100 ; i++)
	{
		this->ideas[i] = ideas;
	}
	return ;
}
void Brain::setIdea ( std::string const & idea, int i ) {

	if (i < 0 || i > 99)
	{
		std::cerr << "Invalid index" << std::endl;
		return ;
	}
	this->ideas[i] = idea;
	return;
}

Brain::~Brain ( void ) {

	std::cout << "[Brain class] Default Destructor" << std::endl;
	return ;
}