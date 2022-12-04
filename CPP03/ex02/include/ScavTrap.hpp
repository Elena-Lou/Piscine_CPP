/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:59:48 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/04 14:32:10 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_CPP
# define SCAVTRAP_CPP
#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
private:
	
public:

	ScavTrap( void );
	ScavTrap( std::string name );
	ScavTrap( ScavTrap const & src );
	~ScavTrap( void );

	ScavTrap & operator=( ScavTrap const & rhs );
	
	unsigned int getHP( void ) const;
	unsigned int getEP( void ) const;
	unsigned int getAD( void ) const;
	
	void guardGate( void );
	void attack( const std::string& target );
};

std::ostream & operator<<( std::ostream & out, ScavTrap const & rhs);

#endif