/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:35:55 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/08 20:58:56 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNAMIC_HPP
# define DYNAMIC_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <exception>

#ifndef SUCCESS
# define SUCCESS 0
#endif

#ifndef FAILURE
# define FAILURE -1
#endif

class Base {
	
public :

	virtual ~Base() {};
};

class A : public Base {};

class B : public Base {};

class C : public Base {};


void identify ( Base* p );

void identify ( Base & p );

Base* generate ( void );

#endif