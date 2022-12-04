/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:21:10 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/04 14:19:22 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"
#include "include/FragTrap.hpp"
#include <iostream>

int	main( void ) {

	ClapTrap c1("Norbert");
	ClapTrap c2("Raoul");
	ClapTrap c3(c1);
	ClapTrap c4;
	c4 = c2;

	std::cout << "\n-------------------\n" << std::endl;

	ScavTrap s1("George");
	ScavTrap s2("Marcel");
	ScavTrap s3(s1);
	ScavTrap s4;

	s4 = s2;

	std::cout << "\n-------------------\n" << std::endl;

	std::cout << "c1 : " << c1 << std::endl;
	std::cout << "c2 : " << c2 << std::endl;
	std::cout << "c3 : " << c3 << std::endl;
	std::cout << "c4 : " << c4 << std::endl;

	std::cout << "\n-------------------\n" << std::endl;

	std::cout << "s1 : " << s1 << std::endl;
	std::cout << "s2 : " << s2 << std::endl;
	std::cout << "s3 : " << s3 << std::endl;
	std::cout << "s4 : " << s4 << std::endl;

	std::cout << "\n-------------------\n" << std::endl;

	c1.attack("Bob");
	c1.beRepaired(115);
	c1.takeDamage(125);
	c1.attack("Franck");
	c2.attack("Machin");

	std::cout << "\n-------------------\n" << std::endl;
	
	s1.attack("bob");
	std::cout << "s1 : " << s1 << std::endl;
	s1.takeDamage(5);
	std::cout << "s1 : " << s1 << std::endl;
	s1.guardGate();
	std::cout << "s1 : " << s1 << std::endl;
	s1.beRepaired(5);
	std::cout << "s1 : " << s1 << std::endl;
	for (int i = 0; i < 50; i++)
	{
		s2.attack("Truc");
		std::cout << "s2 : " << s2 << std::endl;
	
	}
	s2.guardGate();
	s3.attack("Maurice");
	std::cout << "s3 : " << s3 << std::endl;
	s4.takeDamage(100);
	std::cout << "s4 : " << s4 << std::endl;
	s4.guardGate();
	std::cout << "s4 : " << s4 << std::endl;

	std::cout << "\n-------------------\n" << std::endl;

	FragTrap f1("Arod");
	FragTrap f2("Azufel");
	FragTrap f3(f1);
	FragTrap f4;

	f4 = f2;

	std::cout << "\n-------------------\n" << std::endl;

	std::cout << "f1 : " << f1 << std::endl;
	std::cout << "f2 : " << f2 << std::endl;
	std::cout << "f3 : " << f3 << std::endl;
	std::cout << "f4 : " << f4 << std::endl;

	std::cout << "\n-------------------\n" << std::endl;

	f1.attack("Roger");
	std::cout << "f1 : " << f1 << std::endl;
	f2.beRepaired(15);
	std::cout << "f2 : " << f2 << std::endl;
	f3.takeDamage(100);
	std::cout << "f3 : " << f3 << std::endl;
	f3.highFiveGuys();
	std::cout << "f3 : " << f3 << std::endl;
	f4.highFiveGuys();
	std::cout << "f4 : " << f4 << std::endl;
	for (int i = 0; i < 100; i++)
	{
		f4.attack("Truc");
		std::cout << "f4 : " << f4 << std::endl;
	}
	f4.highFiveGuys();


	FragTrap f5(f3);
	std::cout << "f5 : " << f5 << std::endl;

	std::cout << "\n-------------------\n" << std::endl;

}