/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:12:20 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/04 15:16:05 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

WrongCat::WrongCat ( void ) : WrongAnimal() {

    std::cout << "[Class WrongCat] Default Constructor" << std::endl;
    this->type = "WrongCat";
    return ;
}

WrongCat::WrongCat ( WrongCat const & src ) : WrongAnimal ( src ){

    std::cout << "[Class WrongCat] Copy Constructor" << std::endl;
    *this = src;
    return ;
}

WrongCat & WrongCat::operator=( WrongCat const & rhs ) {
    
    std::cout << "[Class WrongCat] Assignment Operator Overload" << std::endl;
    if (this != &rhs )
    	this->type = rhs.type;
    return *this;
}

std::string WrongCat::getType ( void ) const {
    
    return this->type;
}

void WrongCat::makeSound ( void ) const {

    std::cout << "Tout le monde veut devenir un cat..." << std::endl;
    return ;
}

WrongCat::~WrongCat ( void ) {
    
    std::cout << "[Class WrongCat] Default Destructor" << std::endl;
}

std::ostream & operator<<( std::ostream & out, WrongCat const & rhs ) {

    out << rhs.getType();
    return out;
}