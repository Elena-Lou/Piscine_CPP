/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:37:10 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/08 18:44:55 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form ( void ) {
	
	std::cout << "[Form] Default Constructor" << std::endl;
	return ;
}

Form::Form ( std::string name, unsigned int signGrade, unsigned int execGrade ) :
		 _name(name), _signStatus(0), _signGrade(signGrade), _execGrade(execGrade) {
	
	std::cout << "[Form] Constructor" << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	return ;	
}

Form::Form ( Form const & src ) {
	
	*this = src;
	return ;
}

Form & Form::operator=( Form const & rhs ) {
	
	if (this != &rhs)
	{
		this->_signStatus = rhs._signStatus;
		this->_signGrade = rhs._signGrade;
		this->_execGrade = rhs._execGrade;
	}
	return *this;
}

Form::~Form ( void ) {
	
	std::cout << "[Form] Destructor called" << std::endl;
	return ;
}

std::string Form::getName ( void ) const {

	return this->_name;
}

std::string Form::getSignStatus ( void ) const {

	std::string ret;
	
	if (this->_signStatus == 0)
		ret = "not signed";
	else
		ret = "signed";
	return ret;
}

unsigned int Form::getExecGrade ( void ) const {
	
	return this->_execGrade;
}

unsigned int Form::getSignGrade ( void ) const {
	
	return this->_signGrade;
}

void Form::beSigned ( Bureaucrat & bureaucrat ) {
	
	if (this->_signStatus == 1)
	{
		std::cout << "This form is already signed" << std::endl;
	}
	else
	{
		if (bureaucrat.getGrade() > this->_signGrade)
			throw Form::GradeTooLowException();
		this->_signStatus = 1;
	}
}

std::ostream & operator<<( std::ostream & out, Form const & rhs ) {

	out << "Form : " << rhs.getName();
	out << " Status : " << rhs.getSignStatus() << "\n";
	out << "Grade required to sign the form : " << rhs.getSignGrade() << "\n";
	out << "Grade required to execute the form : " << rhs.getExecGrade();

	return out;	
}

const char* Form::GradeTooHighException::what( void ) const throw() {
	
	return ("This grade is too high to perform this task");
}

const char* Form::GradeTooLowException::what( void ) const throw() {
	
	return ("This grade is too low to perform this task");
}
