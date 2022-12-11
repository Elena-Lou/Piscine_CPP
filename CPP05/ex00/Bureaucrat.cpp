/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:14:59 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/11 16:30:23 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

Bureaucrat::Bureaucrat ( void ) {
	
	std::cout << "[Bureaucrat] Default Constructor" << std::endl;
}
Bureaucrat::Bureaucrat ( const std::string name, int grade ) : _name( name ), _grade ( grade ) {
	
	std::cout << "[Bureaucrat] Constructor" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
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

Bureaucrat::~Bureaucrat ( void ) {
	
	std::cout << "[Bureaucrat] Destuctor" << std::endl;
}

std::ostream & operator<<( std::ostream & out, Bureaucrat const & rhs ) {

	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return out;
}

const char* Bureaucrat::GradeTooHighException::what( void ) const throw() {
	
	return ("The grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what( void ) const throw() {
	
	return ("The grade is too low");
}