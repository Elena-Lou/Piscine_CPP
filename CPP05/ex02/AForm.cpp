/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:37:10 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/08 18:44:55 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm ( void ) {
	
	std::cout << "[AForm] Default Constructor" << std::endl;
	return ;
}

AForm::AForm ( std::string name, unsigned int signGrade, unsigned int execGrade, std::string target ) :
		 _name(name), _signStatus(0), _signGrade(signGrade), _execGrade(execGrade), _target(target) {
	
	std::cout << "[AForm] Constructor" << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	return ;	
}

AForm::AForm ( AForm const & src ) {
	
	*this = src;
	return ;
}

AForm & AForm::operator=( AForm const & rhs ) {
	
	if (this != &rhs)
	{
		this->_signStatus = rhs._signStatus;
		this->_signGrade = rhs._signGrade;
		this->_execGrade = rhs._execGrade;
		this->_target = rhs._target;
	}
	return *this;
}

AForm::~AForm ( void ) {
	
	std::cout << "[AForm] Destructor called" << std::endl;
	return ;
}

std::string AForm::getName ( void ) const {

	return this->_name;
}

std::string AForm::getSignStatus ( void ) const {

	std::string ret;
	
	if (this->_signStatus == 0)
		ret = "not signed";
	else
		ret = "signed";
	return ret;
}

unsigned int AForm::getExecGrade ( void ) const {
	
	return this->_execGrade;
}

unsigned int AForm::getSignGrade ( void ) const {
	
	return this->_signGrade;
}

std::string AForm::getTarget ( void ) const {

	return this->_target;
}

void AForm::beSigned ( Bureaucrat & bureaucrat ) {
	
	if (this->_signStatus == 1)
	{
		std::cout << "This form is already signed" << std::endl;
	}
	else
	{
		if (bureaucrat.getGrade() > this->_signGrade)
			throw AForm::GradeTooLowException();
		this->_signStatus = 1;
	}
}

std::ostream & operator<<( std::ostream & out, AForm const & rhs ) {

	out << "AForm : " << rhs.getName();
	out << " Status : " << rhs.getSignStatus() << "\n";
	out << "Grade required to sign the form : " << rhs.getSignGrade() << "\n";
	out << "Grade required to execute the form : " << rhs.getExecGrade();

	return out;	
}

const char* AForm::GradeTooHighException::what( void ) const throw() {
	
	return (" grade is too high to perform this task");
}

const char* AForm::GradeTooLowException::what( void ) const throw() {
	
	return (" grade is too low to perform this task");
}
