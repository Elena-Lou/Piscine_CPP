/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:24:52 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/17 14:14:46 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.h"

int	main( void ) {
	Weapon axe = Weapon("axe");
	Weapon sword = Weapon("Anduril");
	Weapon bow = Weapon("long bow");
	Weapon pan = Weapon("frying pan");
	
	HumanA dwarf("Gimli", axe);
	dwarf.attack();

	HumanA man("Aragorn", sword);
	man.attack();

	HumanA elf("Legolas", bow);
	elf.attack();

	HumanA hobbit("Sam", pan);
	hobbit.attack();
	
	pan.setType("Dar, the hobbit sword");
	hobbit.attack();

	HumanB orc("Beurk");
	orc.attack();
	orc.setWeapon(axe);
	orc.attack();
	axe.setType("pike");
	orc.attack();
}