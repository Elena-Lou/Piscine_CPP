/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:36:46 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/09 13:11:38 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ( void ) {

	Bureaucrat* stagiaire;
	Form*		f1;
	
	try 
	{
		stagiaire = new Bureaucrat("George", 15);

	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;	
	}
	std::cout << *stagiaire << std::endl;
	
	try
	{
		f1 = new Form("f1", 20, 20);
		std::cout << *f1 << std::endl;
		// f1->beSigned(*stagiaire);
		// std::cout << *f1 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		f1->beSigned(*stagiaire);
		std::cout << *f1 << std::endl;

	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		stagiaire->signForm(*f1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	delete stagiaire;
	delete f1;
	


	return 0;	
}