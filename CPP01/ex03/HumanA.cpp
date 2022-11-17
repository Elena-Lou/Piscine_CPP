/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:01:58 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/17 12:36:16 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/HumanA.hpp"
#include "./include/Weapon.hpp"

HumanA::HumanA (std::string name, Weapon& weapon) : _weapon(weapon){

	this->_name = name;
}

void HumanA::attack ( void ) const {
	
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA ( void ) {
	
	return ;
}