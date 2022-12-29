/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:36:46 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/12 13:08:18 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ( void ) {

	std::srand(time(NULL));
	
	try 
	{
		Bureaucrat Bob("Bob", 1);
		ShrubberyCreationForm Test("garden");

		Bob.signForm(Test);
		Bob.executeForm(Test);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n--------------\n" << std::endl;
	
	try 
	{
		Bureaucrat Bob("Bob", 135);
		RobotomyRequestForm Test("Marcel");

		Bob.signForm(Test);
		Bob.executeForm(Test);
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

		Bob.signForm(Test);
		Bob.executeForm(Test);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;	
} 