#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>
#include <exception>

class AForm;

class Intern 
{
private:

protected:

public:

    Intern();
    Intern( Intern const & src);
    ~Intern();

    Intern & operator=( Intern const & rhs );
    AForm* makeForm( std::string form, std::string target);

    class FormDoesNotExist : public std::exception
    {
        public:

            const char* what( void ) const throw();
    };
};

#endif