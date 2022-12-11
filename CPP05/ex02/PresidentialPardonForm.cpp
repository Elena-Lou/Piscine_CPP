/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:47:22 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/11 18:06:16 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm ( void ) : AForm() {

	std::cout << "[Presidential Pardon] Default Constructor" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm ( std::string target ) : AForm( "Presidential Pardon", 25, 5, target) {

	std::cout << "[Presidential Pardon] Default Constructor" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm ( PresidentialPardonForm const & src ) : AForm( src ) {

	std::cout << "[Presidential Pardon] copy constructor" << std::endl;
	return ;
}

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs ) {

	(void)rhs;
	return *this;
}

void PresidentialPardonForm::execute( Bureaucrat const & executor ) const {
	
	if (this->getSignStatus() == "not signed")
	{
		throw AForm::FormNotSignedException();
	}
	else if (executor.getGrade() > this->getExecGrade())
	{
		throw AForm::GradeTooLowException();
	}
	std::cout << this->getTarget() << " has been pardonned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm ( void ) {
	
	std::cout << "[Presidential Pardon] Destructor" << std::endl;
	return ;
}
