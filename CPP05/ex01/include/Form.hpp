/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:37:44 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/11 16:44:15 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class Form
{
	
private:

	const std::string	_name;
	bool				_signStatus;
	unsigned int		_signGrade;
	unsigned int		_execGrade;
	
protected:


public:

	Form();
	Form( std::string name, unsigned int signGrade, unsigned int execGrade );
	Form( Form const & src );
	~Form();
	
	Form & operator=( Form const & rhs );

	std::string 	getName( void ) const ;
	std::string		getSignStatus( void ) const ;
	unsigned int	getSignGrade( void ) const ;
	unsigned int	getExecGrade( void ) const ;

	void			beSigned( Bureaucrat & bureaucrat );

	class GradeTooHighException : public std::exception
	{
		public :
		
			const char* what( void ) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public :

			const char* what( void ) const throw();
	};
};

std::ostream & operator<<( std::ostream & out, Form const & rhs );

#endif