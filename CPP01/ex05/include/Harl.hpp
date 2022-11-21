/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:54:12 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/21 17:01:29 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl
{
private:
	
	void _debug( void );
	void _info( void );
	void _warning( void );
	void _error( void );
	
public:
	Harl( void );
	~Harl( void );
	
	void complain(std::string level);
};


#endif