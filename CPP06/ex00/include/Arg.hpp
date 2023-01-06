/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Arg.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:39:14 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/06 17:27:42 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_HPP
# define ARG_HPP

#include <iostream>
#include <string>
#include <ctype.h>
#include <sstream>

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

#ifndef FAILURE
# define FAILURE -1
#endif

class Arg {

private: 

	std::string _value;
	
	// char		_charValue;
	// int			_intValue;
	// float		_floatValue;
	// double		_doubleValue;
	
	long double _ldValue;
	
public: 

	Arg();
	Arg( Arg const & src );
	~Arg();

	Arg & operator=( Arg const & rhs );

	void setValue( char* value );
	std::string getValue( void ) const ;

	int	whatIsYourType( void ) const ;
	void typeSwitcher( void ) ;

	void convertToLD( void );
	void printValue( void );
	// void printFromInt( void );
	// void printFromFloat( void );
	// void printFromDouble( void );
	// void printFromChar( void );
};

#endif