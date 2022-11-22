/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:54:22 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/22 15:31:36 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl ( void ) {
	
	return ;
}

void Harl::complain( std::string level ) {

	int index;

	std::string levels[] = {
							"DEBUG",
							"INFO",
							"WARNING",
							"ERROR"
	};
	void (Harl::*comments[])( void ) = {
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};

	index = 4; 
	
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			index = i;
			break ;
		}
	}
	
	switch (index)
	{
	case 0:
		(this->*(comments[0]))();
		//fall through
	case 1:
		(this->*(comments[1]))();
		//fall through
	case 2:
		(this->*(comments[2]))();
		//fall through
	case 3:
		(this->*(comments[3]))();
		break ;
	default:
		std::cout << "**DRACARYYYYYYYYYYYYYYYYYS**" << std::endl;
		break ;
	}
}

void Harl::_debug ( void ) {
	
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I am Debug-Harl\n" << std::endl;
}

void Harl::_info ( void ) {
	
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I am Info-Harl\n" << std::endl;
}

void Harl::_warning ( void ) {
	
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I am Warning-Harl\n" << std::endl;
}

void Harl::_error ( void ) {
	
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "I am HErrorL" << std::endl;
}

Harl::~Harl ( void ) {
	
	return ;
}