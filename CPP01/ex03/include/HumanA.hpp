/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:26:23 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/17 12:37:59 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
#include <string>
#include "Weapon.hpp"

class HumanA {
	
private:

	std::string _name;
	Weapon& _weapon;

public :

	HumanA(std::string name, Weapon& weapon);
	~HumanA( void );

	void attack( void ) const;
};
#endif