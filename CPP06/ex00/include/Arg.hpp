/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Arg.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:39:14 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/08 20:41:12 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_HPP
# define ARG_HPP

#include <iostream>
#include <string>
#include <ctype.h>
#include <sstream>

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

#ifndef NAN
# define NAN 3
#endif

class Arg {

private: 

	std::string _value;
	
	char		_charValue;
	int			_intValue;
	float		_floatValue;
	double		_doubleValue;
	
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
	void typeSwitcher( void );

	void printInfinity( void ) const ;
	void printFromInt( void ) const ;
	void printFromFloat( void ) const ;
	void printFromDouble( void  ) const ;
	void printFromChar( void ) const ;
};

#endif