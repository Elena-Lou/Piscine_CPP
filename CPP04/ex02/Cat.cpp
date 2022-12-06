/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:24:33 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/06 17:11:25 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "AAnimal.hpp"
#include <string>
#include <iostream>

Cat::Cat ( void ) : AAnimal() {

    std::cout << "[Class Cat] Default Constructor" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
    return ;
}

Cat::Cat ( Cat const & src ) : AAnimal ( src ){

    std::cout << "[Class Cat] Copy Constructor" << std::endl;
    this->brain = new Brain();
    *(this->brain) = *(src.brain);
    *this = src;
    return ;
}

Cat & Cat::operator=( Cat const & rhs ) {
    
    std::cout << "[Class Cat] Assignment Operator Overload" << std::endl;
    if (this != &rhs )
    {
    	this->type = rhs.type;
        if (this->brain != NULL)
        {
            delete this->brain;
            this->brain = new Brain();
            *(this->brain) = *(rhs.brain);
        }
    }
    return *this;
}

std::string Cat::getType ( void ) const {
    
    return this->type;
}

void Cat::makeSound ( void ) const {

    std::cout << "Mew MEEEEEEWWWW" << std::endl;
    return ;
}

void Cat::setIdeas ( std::string ideas ) {
	
	this->brain->setIdeas(ideas);
	return ;
}

void Cat::setIdea ( std::string idea, int i ) {
	
	this->brain->setIdea(idea, i);
	return ;
}

std::string Cat::getIdea ( int i ) const {

    return this->brain->getIdea(i);
}

Cat::~Cat ( void ) {
    
    std::cout << "[Class Cat] Default Destructor" << std::endl;
    delete this->brain;
}

std::ostream & operator<<( std::ostream & out, Cat const & rhs ) {

    out << rhs.getType();
    return out;
}