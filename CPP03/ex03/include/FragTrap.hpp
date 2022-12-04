/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:42:18 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/04 14:29:31 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include "ClapTrap.hpp"
#include <string>

class FragTrap : virtual public ClapTrap
{
private:
	
public:
	FragTrap();
	FragTrap( std::string name );
	FragTrap( FragTrap const & src );
	virtual ~FragTrap();

	FragTrap & operator=( FragTrap const & rhs );

	unsigned int getHP( void ) const;
	unsigned int getEP( void ) const;
	unsigned int getAD( void ) const;
	
	void highFiveGuys( void );
};

std::ostream & operator<<( std::ostream & out, FragTrap const & rhs);

#endif