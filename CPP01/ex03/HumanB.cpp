/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:01:31 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/17 14:14:32 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "./include/HumanB.hpp"
#include "./include/Weapon.hpp"

HumanB::HumanB (std::string name) : _weapon(NULL) {

	this->_name = name;
}

void HumanB::setWeapon (Weapon& weapon) {

	this->_weapon = &weapon;
}

void HumanB::attack ( void ) const {
	
	if (this->_weapon == NULL)
	{
		std::cout << "** drop their weaponless arms and cries **" << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

HumanB::~HumanB ( void ) {
	
	return ;
}