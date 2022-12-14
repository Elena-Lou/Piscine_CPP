/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:36:49 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/09 10:19:56 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic.hpp"

void identify ( Base* p ) {

	std::cout << "--- Identify type with a pointer --- \n" << std::endl;
	
	if (dynamic_cast<A *>(p))
	{
		std::cout << "ptr is A" << std::endl;
		return ;
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << "ptr is B" << std::endl;
		return ;
	}
	if (dynamic_cast<C *>(p))
	{
		std::cout << "ptr is C" << std::endl;
		return ;
	}
	
}

void identify ( Base & p ) {

	std::cout << "--- Identify type with a reference --- \n" << std::endl;

	try {
		A &test = dynamic_cast<A &>(p);
		std::cout << "ptr is A" << std::endl;
		(void)test;
		return ;
	}
	catch ( std::exception & e) {}
	
	try {
		B &test = dynamic_cast<B &>(p);
		std::cout << "ptr is B" << std::endl;
		(void)test;
		return ;
	}
	catch ( std::exception & e) {}
	
	try {
		C &test = dynamic_cast<C &>(p);
		std::cout << "ptr is C" << std::endl;
		(void)test;
		return ;
	}
	catch ( std::exception & e) {}
}

Base* generate ( void ) {
	
	Base* newbie;	
	int random = std::rand() % 3;

	switch (random) {
		
		case 0 :
			std::cerr << "A" << std::endl;
			newbie = new A;
			return newbie;
		
		case 1 :
			std::cerr << "B" << std::endl;
			newbie = new B;
			return newbie;

		case 2 :
			std::cerr << "C" << std::endl;
			newbie = new C;
			return newbie;
			
		default :
			return NULL;		
	}
	
}