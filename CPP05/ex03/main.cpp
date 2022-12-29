/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:36:46 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/12 12:37:41 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main ( void ) {

	Intern maurice;
	AForm* rrf;
	rrf = NULL;

	try {
		rrf = maurice.makeForm("shrubbery creation", "balcony");
		std::cout << *rrf << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	if (rrf != NULL)
	{
		delete rrf;
		rrf = NULL;
	}
	
	std::cout << "\n------------\n" << std::endl;
	
	try {
		rrf = maurice.makeForm("robotomy request", "Joe");
		std::cout << *rrf << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	if (rrf != NULL)
	{
		delete rrf;
		rrf = NULL;		
	}

	std::cout << "\n------------\n" << std::endl;

	try {
		rrf = maurice.makeForm("presidential pardon", "Joe");
		std::cout << *rrf << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	if (rrf != NULL)
	{
		delete rrf;
		rrf = NULL;		
	}

	std::cout << "\n------------\n" << std::endl;
	
	try {
		rrf = maurice.makeForm("roboto request", "toi");
		std::cout << *rrf << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	if (rrf != NULL)
	{
		delete rrf;
		rrf = NULL;		
	}


	return 0;	
} 