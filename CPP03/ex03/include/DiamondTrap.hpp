/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:54:28 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/01 11:30:15 by elouisia         ###   ########.fr       */
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
	
	void attack( std::string target );
	void whoAmI( void );
};

#endif