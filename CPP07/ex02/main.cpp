/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:44:03 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/11 17:56:02 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main ( void ) {

	Array<int> a;

	Array<int> b(10);
	
	try {
		b.setElements(2);
		std::cout << "b[1] : " << b.getElement(1) << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		return -1;
	}
	Array<int> c(b);
	std::cout << c.getElement(1) << std::endl;
	std::cout << "c[1] : " << c.getElement(1) << std::endl;

	try {
		c.setElements(5);
		std::cout << "c[1] : " << c.getElement(1) << std::endl;
		std::cout << "b[1] : " << b.getElement(1) << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		return -1;
	}

	return 0;
}