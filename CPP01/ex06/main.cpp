/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:54:05 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/22 15:23:58 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int main ( int ac, char** av ) {

	std::string level;
	Harl 		harl;

	if (ac != 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return 1;
	}
	
	level = av[1];
	harl.complain(level);
	return 0;
}