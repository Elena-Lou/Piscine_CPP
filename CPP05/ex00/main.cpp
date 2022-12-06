/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:36:46 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/08 17:00:07 by elouisia         ###   ########.fr       */
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
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;	
	}
	
	try 
	{
		Bureaucrat s2("Maurice", 152);

		std::cout << s2 << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;	
	}
	
	try
	{
		Bureaucrat s3("Maurice", 0);

		std::cout << s3 << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;	
	}


	return 0;	
}