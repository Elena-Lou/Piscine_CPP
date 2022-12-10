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
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main ( void ) {

	

	Intern maurice;
	AForm* rrf;

	rrf = maurice.makeForm("robotomy request", "toi");
	if(rrf == NULL)
	{
		std::cerr << "did not work" << std::endl;
		return 1;
	}
	delete rrf;

	return 0;	
} 