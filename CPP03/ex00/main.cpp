/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:21:10 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/04 12:34:40 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"
#include <iostream>

int	main( void ) {

	ClapTrap c1("Norbert");
	ClapTrap c2("Raoul");
	ClapTrap c3(c2);
	
	ClapTrap c4;

	c4 = c1;

	std::cout << "\n-------------------\n" << std::endl;

	std::cout << "c1 : " << c1 << std::endl;
	std::cout << "c2 : " << c2 << std::endl;
	std::cout << "c3 : " << c3 << std::endl;
	std::cout << "c4 : " << c4 << std::endl;

	std::cout << "\n-------------------\n" << std::endl;

	c1.attack("Bob");
	c1.beRepaired(115);
	for (int i = 0; i < 9; i++)
	{
		c1.attack("Franck");
	}
	c1.takeDamage(125);
	c1.attack("Franck");
	

	std::cout << "\n-------------------\n" << std::endl;

	c2.attack("Bob");
	c2.beRepaired(1);
	c2.takeDamage(1);
	c2.attack("Franck");

	std::cout << "\n-------------------\n" << std::endl;

	c3.attack("Bob");
	c3.beRepaired(5);
	c3.takeDamage(15);
	c3.attack("Franck");

	std::cout << "\n-------------------\n" << std::endl;

	c4.attack("Bob");
	c4.beRepaired(0);
	c4.takeDamage(2);
	c4.attack("Franck");

	std::cout << "\n-------------------\n" << std::endl;

	return 0;
}