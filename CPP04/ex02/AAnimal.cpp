/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:01:55 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/06 17:17:23 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/AAnimal.hpp"
#include <iostream>
#include <string>

AAnimal::AAnimal ( void ) {
    
    std::cout << "[Class AAnimal] Default Constructor" << std::endl;
    this->type = "Cow";
    return ;
}

AAnimal::AAnimal ( AAnimal const & src ) {
    
    std::cout << "[Class AAnimal] Copy Constructor" << std::endl;
    *this = src;
    return ;
}

AAnimal & AAnimal::operator=( AAnimal const & rhs ) {
    
    std::cout << "[Class AAnimal] Assignment Operator Overload" << std::endl;
    if (this != &rhs)
        this->type = rhs.type;
    return *this;
}

AAnimal::~AAnimal ( void ) { 

    std::cout << "[Class Animal] Default Destructor" << std::endl;
    return ;
}

std::ostream & operator<<( std::ostream & out, AAnimal const & rhs ) {

    out << rhs.getType();
    return out;
}

