/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:13:49 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/04 15:29:35 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal ( void ) {
    
    std::cout << "[Class WrongAnimal] Default Constructor" << std::endl;
    this->type = "WrongAnimal";
    return ;
}

WrongAnimal::WrongAnimal ( WrongAnimal const & src ) {
    
    std::cout << "[Class WrongAnimal] Copy Constructor" << std::endl;
    *this = src;
    return ;
}

WrongAnimal & WrongAnimal::operator=( WrongAnimal const & rhs ) {
    
    std::cout << "[Class WrongAnimal] Assignment Operator Overload" << std::endl;
    if (this != &rhs)
        this->type = rhs.type;
    return *this;
}

std::string WrongAnimal::getType ( void ) const {

    return this->type;
}

void WrongAnimal::makeSound ( void ) const {

    std::cout << "**plays the saxo**" << std::endl;
    return ;
}

WrongAnimal::~WrongAnimal ( void ) { 

    std::cout << "[Class WrongAnimal] Default Destructor" << std::endl;
    return ;
}

std::ostream & operator<<( std::ostream & out, WrongAnimal const & rhs ) {

    out << rhs.getType();
    return out;
}