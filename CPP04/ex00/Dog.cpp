/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:34:31 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/07 13:31:08 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include <string>
#include <iostream>

Dog::Dog ( void ) : Animal() {

    std::cout << "[Class Dog] Default Constructor" << std::endl;
    this->type = "Dog";
    return ;
}

Dog::Dog ( Dog const & src ) : Animal ( src ) {
    
    std::cout << "[Class Dog] Copy Constructor" << std::endl;
    *this = src;
    return;

}

Dog & Dog::operator=( Dog const & rhs ) {
    
    std::cout << "[Class Dog] Assignment Operator Overload" << std::endl;
    if (this != &rhs )
    	this->type = rhs.type;
    return *this;
}

void Dog::makeSound ( void ) const {

    std::cout << "Woof Wooooooof" << std::endl;
    return ;
}

Dog::~Dog ( void ) {
    
    std::cout << "[Class Dog] Default Destructor" << std::endl;
}

std::ostream & operator<<( std::ostream & out, Dog const & rhs ) {

    out << rhs.getType();
    return out;
}