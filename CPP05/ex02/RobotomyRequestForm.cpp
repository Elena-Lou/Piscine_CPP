/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:47:36 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/11 18:06:19 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm ( void ) : AForm() {

	std::cout << "[Robotomy Request] Default Constructor" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm ( std::string target ) : AForm( "Robotomy Request", 72, 45, target) {

	std::cout << "[Robotomy Request] Default Constructor" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm ( RobotomyRequestForm const & src ) : AForm( src ) {

	std::cout << "[Robotomy Request] copy constructor" << std::endl;
	return ;
}

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs ) {

	(void)rhs;
	return *this;
}

void RobotomyRequestForm::execute( Bureaucrat const & executor ) const {
	
	int random;
	std::srand(time(NULL));
	if (this->getSignStatus() == "not signed")
	{
		throw AForm::FormNotSignedException();
	}
	else if (executor.getGrade() > this->getExecGrade())
	{
		throw AForm::GradeTooLowException();
	}
	std::cout << "*** drilling noise ***" << std::endl;
	random = std::rand() % 4;
	if (random % 2 == 1)
		std::cout << this->getTarget() << " has been successfully robotomised" << std::endl;
	else
		std::cout << "Oh no ! Robotomy on " << this->getTarget() <<  " failed !" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm ( void ) {
	
	std::cout << "[Robotomy Request] Destructor" << std::endl;
	return ;
}

