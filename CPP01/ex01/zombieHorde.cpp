/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:44:30 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/15 17:13:56 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie* zombieHorde(int N, std::string name) {
	
	Zombie* zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombies[i].setName(name);
		zombies[i].announce();
	}
	return zombies;
}