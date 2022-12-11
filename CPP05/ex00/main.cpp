/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:36:46 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/11 16:28:43 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
# include <iostream>
# include <string>

int main ( void ) {

	try 
	{
		Bureaucrat stagiaire("George", 150);

		std::cout << stagiaire << std::endl;
		
		stagiaire.demotion();
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;	
	}

	std::cout << "\n--------------\n" << std::endl;

	try 
	{
		Bureaucrat sb("Maurice", 152);

		std::cout << sb << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;	
	}

	std::cout << "\n--------------\n" << std::endl;

	try
	{
		Bureaucrat b3("Maurice", 0);

		std::cout << b3 << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;	
	}
	
	std::cout << "\n--------------\n" << std::endl;

	try
	{
		Bureaucrat b4("Maurice", 1);

		std::cout << b4 << std::endl;
		b4.demotion();
		std::cout << b4 << std::endl;
		b4.promotion();
		std::cout << b4 << std::endl;
		b4.promotion();
		std::cout << b4 << std::endl;		
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;	
	}

	return 0;	
}