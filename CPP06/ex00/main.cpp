/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:22:03 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/06 16:55:13 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Arg.hpp"

int main ( int ac, char** av ) {

	Arg arg;
	
	if (ac != 2)
	{
		std::cerr << "Invalid input" << std::endl;
		return FAILURE;
	}
	arg.setValue(av[1]);
	arg.typeSwitcher();
	arg.printValue();

	return 0;
}