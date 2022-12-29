/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:41:35 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/15 16:42:59 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie ( void ) {
	
	return ;
}

void Zombie::setName (std::string name) {

	this->name = name;
}

void Zombie::announce ( void ) {
	
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie ( void ) {

	std::cout << this->name << " exploded" << std::endl;

	return ;
}