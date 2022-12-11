/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:36:46 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/11 18:04:07 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ( void ) {

	try 
	{
		Bureaucrat Bob("Bob", 40);
		ShrubberyCreationForm Test("garden");

	// Test.beSigned(Bob);
		Test.execute(Bob);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n--------------\n" << std::endl;
	
	try 
	{
		Bureaucrat Bob("Bob", 140);
		RobotomyRequestForm Test("Marcel");

		Test.beSigned(Bob);
		Test.execute(Bob);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n--------------\n" << std::endl;

	try 
	{
		Bureaucrat Bob("Bob", 15);
		PresidentialPardonForm Test("Marcel");

		Test.beSigned(Bob);
		Test.execute(Bob);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;	
} 