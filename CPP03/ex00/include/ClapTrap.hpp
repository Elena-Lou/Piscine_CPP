/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:31:41 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/28 19:55:48 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <string>

class ClapTrap
{
private:
	
	std::string 	_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
	

public:

	ClapTrap( void );
	ClapTrap( std::string name );
	ClapTrap(ClapTrap const & src );
	~ClapTrap();

	std::string getName() const;
	
	ClapTrap & operator=( ClapTrap const & rhs );

	void 		attack( const std::string& target );
	void 		takeDamage( unsigned int amount );
	void 		beRepaired( unsigned int amount );
	
};

std::ostream & operator<<( std::ostream & out, ClapTrap const & rhs);


#endif