/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:59:48 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/01 11:30:24 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_CPP
# define SCAVTRAP_CPP
#include "ClapTrap.hpp"
#include <string>

class ScavTrap : virtual public ClapTrap
{
private:
	
public:

	ScavTrap( void );
	ScavTrap( std::string name );
	ScavTrap( ScavTrap const & src );
	virtual ~ScavTrap( void );

	ScavTrap & operator=( ScavTrap const & rhs );
	void guardGate( void );
	void attack( const std::string& target );
};

#endif