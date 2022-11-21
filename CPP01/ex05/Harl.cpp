/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:54:22 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/21 18:08:12 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl ( void ) {
	
	return ;
}

void Harl::complain( std::string level ) {

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

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*(comments[i]))();
			return ;
		}
	}
	std::cout << "**DRACARYYYYYYYYYYYYYYYYYS**" << std::endl;
	return ;
}

void Harl::_debug ( void ) {
	
	std::cout << "I am Debug-Harl" << std::endl;
}

void Harl::_warning ( void ) {
	
	std::cout << "I am Warning-Harl" << std::endl;
}

void Harl::_info ( void ) {
	
	std::cout << "I am Info-Harl" << std::endl;
}

void Harl::_error ( void ) {
	
	std::cout << "I am HErrorL" << std::endl;
}

Harl::~Harl ( void ) {
	
	return ;
}