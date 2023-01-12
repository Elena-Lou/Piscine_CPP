/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:23:48 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/12 16:20:03 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main ( void ) {

	std::vector<int> firstVector (4, 100);
	
	std::vector<int>::iterator found;
	
	try
	{
		found = easyfind(firstVector, 100);
	}
	catch ( std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	

}