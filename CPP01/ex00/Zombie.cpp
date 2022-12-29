/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:09:03 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/15 15:52:26 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie ( void ) {
	
	return ;
}

void Zombie::setName (std::string name) {

	this->_name = name;
}

std::string Zombie::getName( void ) const {
	return this->_name;
}

void Zombie::announce ( void ) {
	
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie ( void ) {

	std::cout << this->_name << " exploded" << std::endl;

	return ;
}