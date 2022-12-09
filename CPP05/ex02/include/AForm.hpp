/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:37:44 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/09 16:13:40 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class AForm
{
	
private:

	const std::string	_name;
	bool				_signStatus;
	unsigned int		_signGrade;
	unsigned int		_execGrade;
	std::string			_target;
	
protected:


public:

	AForm();
	AForm( std::string name, unsigned int signGrade, unsigned int execGrade, std::string target );
	AForm( AForm const & src );
	virtual ~AForm();
	
	AForm & operator=( AForm const & rhs );

	std::string 	getName( void ) const;
	std::string		getSignStatus( void ) const;
	unsigned int	getSignGrade( void ) const;
	unsigned int	getExecGrade( void ) const;
	std::string		getTarget( void ) const;

	void			beSigned( Bureaucrat & bureaucrat );
	virtual void	execute( Bureaucrat const & executor ) const = 0;

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

std::ostream & operator<<( std::ostream & out, AForm const & rhs );

#endif