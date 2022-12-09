/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:36:46 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/09 17:29:52 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main ( void ) {

	try 
	{
		
	Bureaucrat Bob("Bob", 40);
	ShrubberyCreationForm Test("garden");

	Test.execute(Bob);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try 
	{
		
	Bureaucrat Bob("Bob", 40);
	RobotomyRequestForm Test("Marcel");

	Test.execute(Bob);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;	
}