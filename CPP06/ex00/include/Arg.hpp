/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Arg.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:39:14 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/10 11:22:05 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_HPP
# define ARG_HPP

#include <iostream>
#include <string>
#include <ctype.h>
#include <sstream>
#include <limits>
#include <cerrno>
#include <cstdlib>
#include <iomanip>
#include <cmath>

#ifndef FAILURE
# define FAILURE -1
#endif

#ifndef SUCCESS
# define SUCCESS 0
#endif

#ifndef INT
# define INT 1
#endif

#ifndef FLOAT
# define FLOAT 2
#endif

#ifndef DOUBLE
# define DOUBLE 3
#endif

#ifndef CHAR
# define CHAR 4
#endif

#ifndef NEGINF
# define NEGINF 1
#endif

#ifndef POSINF
# define POSINF 2
#endif

#ifndef NANVAL
# define NANVAL 3
#endif

class Arg {

private: 

	std::string _value;
	
	char		_charValue;
	int			_infinityValue;
	
public: 

	Arg();
	Arg( Arg const & src );
	~Arg();

	Arg & operator=( Arg const & rhs );

	void setValue( char* value );
	std::string getValue( void ) const ;
	
	int infinityCheck( void ) const ;
	int	whatIsYourType( void );
	void typeChecker( void );

	void printInfinity( void ) const ;
	void printValue( void ) const ;
	
	size_t		_precision;
};

#endif