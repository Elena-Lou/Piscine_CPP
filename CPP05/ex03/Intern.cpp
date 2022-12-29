/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:22:57 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/12 12:41:08 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern ( void ) {

    std::cout << "[Intern] Constructor" << std::endl;
    return ;
}

Intern::Intern ( Intern const & src ) {

    *this = src;
    return ;
}

Intern::~Intern ( void ) {

    std::cout << "[Intern] Destructor" << std::endl;
}

Intern & Intern::operator=( Intern const & rhs ) {

    (void)rhs;
    return *this;
}

AForm* createShrubberyForm( std::string target ) {

   AForm* shrubberyForm = new ShrubberyCreationForm(target);
    return shrubberyForm;
}

AForm* createPresidentialPardonForm( std::string target ) {

    AForm* presidentialPardonForm = new PresidentialPardonForm(target);
    return presidentialPardonForm;
}

AForm* createRobotomyRequestForm( std::string target ) {

   AForm* robotomyRequestForm = new RobotomyRequestForm(target);
    return robotomyRequestForm;
}

AForm* Intern::makeForm ( std::string form, std::string target ){

    AForm* newForm;
    AForm* (*Forms[3])(std::string) = {createShrubberyForm, createRobotomyRequestForm, createPresidentialPardonForm};
    std::string formName[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    for (int i = 0; i < 3; i++)
    {
        if (formName[i] == form)
        {
            newForm = (*Forms[i])(target);
            std::cout << "Intern creates " << form << " form" << std::endl;
            return newForm;
        }
    }
    throw Intern::FormDoesNotExist();
    return NULL;
}

const char* Intern::FormDoesNotExist::what ( void ) const throw() {

   return ("This form doesn't exist.\nAvailable forms are : \"shrubbery creation\", \"robotomy request\" and \"presidential pardon\"");
}