/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:31:54 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/22 12:04:24 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Weapon.hpp"
#include <iostream>

Weapon::Weapon ( void ) : _type("") {
	
	return ;
}

Weapon::Weapon ( std::string type ) {
	
	this->_type = type;
	return ;
}

void Weapon::setType ( std::string type ) {
	
	this->_type = type;
}

const std::string& Weapon::getType ( void ) const {

	return this->_type;	
}

Weapon::~Weapon ( void ) {
	
	return ;
}