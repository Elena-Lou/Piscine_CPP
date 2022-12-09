/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:46:21 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/09 16:40:08 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include <string>
#include <iostream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
private:
	
	ShrubberyCreationForm();

public:

	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( ShrubberyCreationForm const & src );
	~ShrubberyCreationForm();

	ShrubberyCreationForm & operator=( ShrubberyCreationForm const & rhs );

	void	execute( Bureaucrat const & executor ) const;
};

#endif