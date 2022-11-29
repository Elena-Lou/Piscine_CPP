/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:21:10 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/29 15:23:17 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"
#include <iostream>

int	main( void ) {

	ClapTrap c1("Norbert");
	ClapTrap c2("Raoul");
	ClapTrap c3(c1);
	ClapTrap c4;
	c4 = c2;

	ScavTrap s1("George");
	ScavTrap s2("Marcel");
	ScavTrap s3(s1);
	ScavTrap s4;

	s4 = s2;

	std::cout << "c1 : " << c1 << std::endl;
	std::cout << "c2 : " << c2 << std::endl;
	std::cout << "c3 : " << c3 << std::endl;
	std::cout << "c4 : " << c4 << std::endl;
	std::cout << "s1 : " << s1 << std::endl;
	std::cout << "s2 : " << s2 << std::endl;
	std::cout << "s3 : " << s3 << std::endl;
	std::cout << "s4 : " << s4 << std::endl;


	c1.attack("Bob");
	c1.beRepaired(115);
	c1.takeDamage(125);
	c1.attack("Franck");
	c2.attack("Machin");
	s1.attack("bob");
	s1.takeDamage(5);
	s1.guardGate();
	s1.beRepaired(5);
	s3.attack("Maurice");
	s4.takeDamage(100);
	s4.guardGate();

}