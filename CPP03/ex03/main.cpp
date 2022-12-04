/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:21:10 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/04 14:41:41 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"
#include "include/FragTrap.hpp"
#include "include/DiamondTrap.hpp"
#include <iostream>

int	main( void ) {

	DiamondTrap d1("Arraxas");
	
	std::cout << "\n-------------\n" << std::endl;
	
	DiamondTrap d2("Styrax");
	
	std::cout << "\n-------------\n" << std::endl;
	
	DiamondTrap d3(d1);
	
	std::cout << "\n-------------\n" << std::endl;
	
	DiamondTrap d4;

	d4 = d2;

	std::cout << "\n-------------\n" << std::endl;

	std::cout << "d1 : " << d1 << std::endl;
	std::cout << "d2 : " << d2 << std::endl;
	std::cout << "d3 : " << d3 << std::endl;
	std::cout << "d4 : " << d4 << std::endl;

	std::cout << "\n-------------\n" << std::endl;
	
	d1.whoAmI();
	d2.whoAmI();
	d3.whoAmI();
	d4.whoAmI();

	std::cout << "\n-------------\n" << std::endl;

	d1.attack("Bob");
	d1.beRepaired(115);
	d1.takeDamage(125);
	d1.guardGate();
	d1.highFiveGuys();
	d1.attack("Franck");
	d1.beRepaired(5);
	std::cout << "d1 : " << d1 << std::endl;
	
	std::cout << "\n-------------\n" << std::endl;
	
	d2.attack("Machin");
	d2.takeDamage(5);
	d2.beRepaired(15);
	std::cout << "d2 : " << d2 << std::endl;
	
	std::cout << "\n-------------\n" << std::endl;
	
	d3.attack("Maurice");
	d3.takeDamage(100);
	d3.highFiveGuys();
	std::cout << "d3 : " << d3 << std::endl;
	
	std::cout << "\n-------------\n" << std::endl;
	
	d4.takeDamage(100);
	d4.attack("bob");
	d4.guardGate();
	d4.highFiveGuys();
	std::cout << "d4 : " << d4 << std::endl;

	std::cout << "\n-------------\n" << std::endl;

	DiamondTrap d5(d2);
	std::cout << "d5 : " << d5 << std::endl;

	

	return 0;
}