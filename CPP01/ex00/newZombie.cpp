/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:56:44 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/15 16:19:25 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <new>

Zombie* newZombie( std::string name ) {
	
	Zombie* zombie = new Zombie;
	zombie->setName(name);
	zombie->announce();
	return zombie;
}