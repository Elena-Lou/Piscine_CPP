/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:54:34 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/16 17:55:11 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Zombie.h"

int	main( void ) {
	Zombie* Arnold;
	Zombie* Capuche;
	
	Arnold = newZombie("Arnold");
	if (Arnold == NULL)
		return 1;
	
	randomChump("Norbert");
	
	Capuche = newZombie("Capuche");
	if (Capuche == NULL)
		return 1;
		
	randomChump("Newton");

	delete Arnold;
	delete Capuche;

	return 0;	
}