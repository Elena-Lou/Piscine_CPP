/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:24:33 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/05 17:01:55 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include <string>
#include <iostream>

Cat::Cat ( void ) : Animal() {

    std::cout << "[Class Cat] Default Constructor" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
    return ;
}

Cat::Cat ( Cat const & src ) : Animal ( src ){

    std::cout << "[Class Cat] Copy Constructor" << std::endl;
    *this = src;
    this->brain = new Brain();
    *(this->brain) = *(src.brain);
    return ;
}

Cat & Cat::operator=( Cat const & rhs ) {
    
    std::cout << "[Class Cat] Assignment Operator Overload" << std::endl;
    if (this != &rhs )
    {
    	this->type = rhs.type;
        this->brain = new Brain();
        *(this->brain) = *(rhs.brain);
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

Cat::~Cat ( void ) {
    
    std::cout << "[Class Cat] Default Destructor" << std::endl;
    delete this->brain;
}

std::ostream & operator<<( std::ostream & out, Cat const & rhs ) {

    out << rhs.getType();
    return out;
}