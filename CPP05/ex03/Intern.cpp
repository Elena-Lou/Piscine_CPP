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
            std::cout << formName[i] << std::endl;
            newForm = (*Forms[i])(target);
            return newForm;
        }
    }
    std::cerr << "this form doesn't exist" << std::endl;
    return NULL;
}