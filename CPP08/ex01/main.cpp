/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:56:20 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/16 16:47:53 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main ( void ) {

	std::srand(time(NULL));
	

	std::cout << "\n --- SPAN ON A SIZE 1 VECTOR ---\n" << std::endl;
	try {
		
		Span span;
		std::cout << "longest span : " << span.longestSpan() << std::endl;
	
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n --- ADDNUMBER WHEN VECTOR ALREADY FULL ---\n" << std::endl;
	try {
		
		Span span1(8);

		span1.addNumbers(2);
		span1.addNumber(8);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n --- OPERATOR[] OVERLOAD ---\n" << std::endl;
	try {
		
		Span spanBis(8);

		spanBis.addRandomNumbers();
		std:: cout << "spanBis[3] : " << spanBis[3] << std::endl;
		std:: cout << "spanBis[12] : " << spanBis[12] << std::endl;
		// std:: cout << "spanBis[-3] : " << spanBis[-3] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	
	std::cout << "\n --- ADDNUMBERS ---\n" << std::endl;

	try {
		
		Span span2(10);
		span2.addNumbers(5);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n --- ADDRANDOMNUMBERS ---\n" << std::endl;

	try {
			
		Span span3(8);
		span3.addRandomNumbers();
		std::cout << "longest span : " << span3.longestSpan() << std::endl;
		std::cout << "shortest span : " << span3.shortestSpan() << std::endl;

	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n--- MAIN FROM SUBJECT ---\n" << std::endl;
	
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	return 0;
}