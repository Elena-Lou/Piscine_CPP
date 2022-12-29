/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:36:46 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/12 14:04:34 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ( void ) {

	Bureaucrat* intern;
	Bureaucrat* boss;
	Form*		f1;
	
	try 
	{
		intern = new Bureaucrat("George", 150);
		std::cout << *intern << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;	
	}

	std::cout << "\n--------------\n" << std::endl;
	
	try
	{
		f1 = new Form("f1", 20, 1);
		std::cout << *f1 << std::endl;
		intern->signForm(*f1);
		std::cout << *f1 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n--------------\n" << std::endl;

	try
	{
		boss = new Bureaucrat("Boss", 2);
		boss->signForm(*f1);
		std::cout << *f1 << std::endl;

	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n--------------\n" << std::endl;

	try
	{
		boss->signForm(*f1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	delete intern;
	delete boss;
	delete f1;

	return 0;	
}