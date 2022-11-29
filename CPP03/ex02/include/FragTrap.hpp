/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:42:18 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/29 16:12:41 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap
{
private:
	
public:
	FragTrap();
	FragTrap( std::string name );
	FragTrap( FragTrap const & src );
	~FragTrap();

	FragTrap & operator=( FragTrap const & rhs );
	
	void highFiveGuys( void );
};

#endif