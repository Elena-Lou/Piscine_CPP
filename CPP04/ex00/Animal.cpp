/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:01:55 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/03 11:41:04 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal ( void ) {
    
    std::cout << "[Class Animal] Default Constructor" << std::endl;
    this->type = "T-Rex";
    return ;
}

Animal::Animal ( Animal const & src ) {
    
    std::cout << "[Class Animal] Copy Constructor" << std::endl;
    *this = src;
    return ;
}

Animal & Animal::operator=( Animal const & rhs ) {
    
    std::cout << "[Class Animal Assignment Operator Overload" << std::endl;
    if (this != &rhs)
        this->type = rhs.type;
    return *this;
}

std::string Animal::getType ( void ) const {

    return this->type;
}

void Animal::makeSound ( void ) const {

    std::cout << "Meuuuuuuuuh" << std::endl;
    return ;
}

Animal::~Animal ( void ) { 

    std::cout << "[Class Animal] Default Destructor" << std::endl;
    return ;
}

std::ostream & operator<<( std::ostream & out, Animal const & rhs ) {

    out << rhs.getType();
    return out;
}

