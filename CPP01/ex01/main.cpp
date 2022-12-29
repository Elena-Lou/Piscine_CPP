/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:34:04 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/15 17:13:35 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main ( void ) {
	
	Zombie* horde;

	horde = zombieHorde(3, "Cassos");
	if (horde == NULL)
		return 1;
	delete [] horde;
	
	return 0;	
}