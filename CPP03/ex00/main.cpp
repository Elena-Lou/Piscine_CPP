/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:21:10 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/28 19:43:19 by elouisia         ###   ########.fr       */
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

	std::cout << "c1 : " << c1 << std::endl;
	std::cout << "c2 : " << c2 << std::endl;
	std::cout << "c3 : " << c3 << std::endl;
	std::cout << "c4 : " << c4 << std::endl;

	c1.attack("Bob");
	c1.beRepaired(115);
	c1.takeDamage(125);
	c1.attack("Franck");


	std::cout << "bouh " << std::endl;
}