/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:23:30 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/12 12:33:55 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    Intern( Intern const & src );
    ~Intern();

    Intern & operator=( Intern const & rhs );
    AForm* makeForm( std::string form, std::string target );

    class FormDoesNotExist : public std::exception
    {
        public:

            const char* what( void ) const throw();
    };
};

#endif