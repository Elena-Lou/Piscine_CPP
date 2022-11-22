/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:34:04 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/22 14:42:21 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <ctype.h>
#include <stdlib.h>
#include <cstring>

int ft_check_arg(int ac, char* av, long* n) {
	
	int i;
	
	if (ac != 3)
	{
		std::cerr << "Usage: ./horde nb_of_zombies name_of_zombies" << std::endl;
		return 1;
	}
	
	i = strlen(av);
	if (i > 11)
	{
		std::cerr << "Invalid type of argument" << std::endl;
		return 1;
	}
	
	for (int j = 0; j < i; j++)
	{
		if (!isdigit(av[j]))
		{
		std::cerr << "Invalid type of argument" << std::endl;
		return 1;
		}
	}
	
	*n = atol(av);
	if (*n < 1 || *n > 2147483647)
	{
		std::cerr << "Invalid type of argument" << std::endl;
		return 1;
	}
	return 0;
}

int	main ( int ac, char **av ) {
	
	long n;
	Zombie* horde;
	
	if (ft_check_arg(ac, av[1], &n))
		return 1;

	horde = zombieHorde((int)n, av[2]);
	if (horde == NULL)
		return 1;
	delete [] horde;
	
	return 0;	
}