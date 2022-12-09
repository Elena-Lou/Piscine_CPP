/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:10:20 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/09 14:26:42 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class AForm;

class Bureaucrat
{
	
private:
	
	const std::string 	_name;
	unsigned int		_grade;

	Bureaucrat();
	
public:

	Bureaucrat( std::string name, int grade );
	Bureaucrat( Bureaucrat const & src );
	~Bureaucrat();

	Bureaucrat & operator=( Bureaucrat const & rhs );

	unsigned int	getGrade( void ) const;
	std::string		getName( void ) const;

	void			promotion( void );
	void 			demotion( void );
	void			signForm(AForm & formToSign );

	class GradeTooHighException : public std::exception
	{
		public:
		
			const char* what( void ) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		
			const char* what( void ) const throw();
	};

	

	
};

std::ostream & operator<<( std::ostream & out, Bureaucrat const & rhs );

#endif