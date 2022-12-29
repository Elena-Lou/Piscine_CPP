/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Arg.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:39:14 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/29 17:48:04 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_HPP
# define ARG_HPP

#include <iostream>
#include <string>

class Arg {

private: 

	std::string _value;
	
public: 

	Arg();
	Arg( Arg const & src );
	~Arg();

	Arg & operator=( Arg const & rhs );

	void setValue( char* value );
	std::string getValue( void );
};

#endif