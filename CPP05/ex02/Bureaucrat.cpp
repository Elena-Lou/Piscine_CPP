/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:14:59 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/11 18:07:19 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat ( void ) {
	
	std::cout << "[Bureaucrat] Default Constructor" << std::endl;
}
Bureaucrat::Bureaucrat ( const std::string name, int grade ) : _name( name ), _grade ( grade ) {
	
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "[Bureaucrat] Constructor" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat ( Bureaucrat const & src ) {
	
	std::cout << "[Bureaucrat] Copy Constructor" << std::endl;
	*this = src;
	return ;
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & rhs ) {
	
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
	}
	return *this;
}

unsigned int Bureaucrat::getGrade ( void ) const {

	return this->_grade;
}

std::string Bureaucrat::getName ( void ) const {

	return this->_name;
}

void Bureaucrat::promotion ( void ) {
	
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
	return ;
}

void Bureaucrat::demotion ( void ) {
	
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
	return ;
}

void Bureaucrat::signForm ( AForm & formToSign ) {
	
	if (formToSign.getSignStatus() == "signed")
	{
		std::cout << this->_name << " couldn't sign form because it is already signed" << std::endl;
	}
	else
	{
		try 
		{
			formToSign.beSigned(*this);
			std::cout << this->_name << " signed " << formToSign.getName() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << this->_name << " couldn't sign form because " << "their" << e.what() <<  std::endl;
		}
	}
}

void Bureaucrat::executeForm ( AForm const & form ) {

	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << this->_name << " couldn't execute " << form.getName() << " because " << "their" << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat ( void ) {
	
	std::cout << "[Bureaucrat] Destructor" << std::endl;
}

std::ostream & operator<<( std::ostream & out, Bureaucrat const & rhs ) {

	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return out;
}

const char* Bureaucrat::GradeTooHighException::what( void ) const throw() {
	
	return ("This grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what( void ) const throw() {
	
	return ("This grade is too low");
}