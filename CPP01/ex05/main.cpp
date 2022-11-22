/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:54:05 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/22 15:23:29 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int main ( void ) {

	std::string level;
	Harl 		harl;

	while (1)
	{
		if (std::cin.eof())
			return 1;
		std::cout << "\nType a level for Harl to make a comment : DEBUG, INFO, WARNING or ERROR" << std::endl;
		getline(std::cin, level);
		if (level != "exit")
			harl.complain(level);
		else
			return 0;
	}

}