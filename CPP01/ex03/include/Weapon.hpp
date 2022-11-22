/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:28:52 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/22 12:32:25 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <string>

class Weapon {
	
private:

	std::string _type;

public:

	Weapon( void );
	Weapon( std::string type );
	~Weapon( void );
	
	void setType( std::string type );
	const std::string& getType( void ) const;
};

#endif