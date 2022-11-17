/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:26:56 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/17 14:14:40 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
#include "Weapon.hpp"
#include <string>

class HumanB {
	
private:

	std::string _name;
	Weapon* _weapon;

public :

	HumanB( void);
	HumanB(std::string name);
	~HumanB( void ); 	

	void attack( void ) const;
	void setWeapon(Weapon& weapon);
};

#endif