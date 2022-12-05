/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:34:31 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/05 17:39:31 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include <string>
#include <iostream>

Dog::Dog ( void ) : Animal() {

    std::cout << "[Class Dog] Default Constructor" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
    return ;
}

Dog::Dog ( Dog const & src ) : Animal ( src ) {
    
    std::cout << "[Class Dog] Copy Constructor" << std::endl;
    *this = src;
    this->brain = new Brain();
    *(this->brain) = *(src.brain);
    return;

}

Brain* Dog::getBrain ( void ) const {

    return this->brain;
}

std::string Dog::getIdea ( int i ) const {

    return this->brain->getIdea(i);
}

Dog & Dog::operator=( Dog const & rhs ) {
    
    std::cout << "[Class Dog] Assignment Operator Overload" << std::endl;
    if (this != &rhs )
    {
    	this->type = rhs.type;
        this->brain = new Brain();
        *(this->brain) = *(rhs.brain);
    }
    return *this;
}


std::string Dog::getType ( void ) const {
    
    return this->type;
}

void Dog::makeSound ( void ) const {

    std::cout << "Woof Wooooooof" << std::endl;
    return ;
}

Dog::~Dog ( void ) {
    
    std::cout << "[Class Dog] Default Destructor" << std::endl;
    delete this->brain;
}

std::ostream & operator<<( std::ostream & out, Dog const & rhs ) {

    out << rhs.getType();
    return out;
}