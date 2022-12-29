/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:45:24 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/12 12:47:18 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
private:
	
	RobotomyRequestForm();

public:

	RobotomyRequestForm( std::string target );
	RobotomyRequestForm( RobotomyRequestForm const & src );
	~RobotomyRequestForm();

	RobotomyRequestForm & operator=( RobotomyRequestForm const & rhs );

	void	execute( Bureaucrat const & executor ) const;
};

#endif