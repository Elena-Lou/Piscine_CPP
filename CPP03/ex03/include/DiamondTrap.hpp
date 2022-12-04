/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:54:28 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/04 14:37:29 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:

	std::string _name;
	
public:

	DiamondTrap();
	DiamondTrap( std::string name );
	DiamondTrap( DiamondTrap const & src );
	~DiamondTrap();

	DiamondTrap & operator=( DiamondTrap const & rhs );
	
	unsigned int getHP( void ) const;
	unsigned int getEP( void ) const;
	unsigned int getAD( void ) const;
	
	void attack( std::string target );
	void whoAmI( void );
};

std::ostream & operator<<( std::ostream & out, DiamondTrap const & rhs);

#endif