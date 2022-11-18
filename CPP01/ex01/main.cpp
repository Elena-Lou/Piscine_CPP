/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:34:04 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/16 17:54:28 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Zombie.h"
#include <ctype.h>
#include <stdlib.h>

int	main ( int ac, char **av ) {
	
	if (ac != 3)
	{
		std::cout << "Usage: ./horde nb_of_zombies name_of_zombies" << std::endl;
		return 1;
	}
	Zombie* horde;

	horde = zombieHorde(atoi(av[1]), av[2]);
	if (horde == NULL)
		return 1;
	delete [] horde;
	
	return 0;	
}