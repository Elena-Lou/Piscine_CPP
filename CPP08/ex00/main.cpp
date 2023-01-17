/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:23:48 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/17 11:55:33 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main ( void ) {
	
	std::cout << "\n--- VECTOR ---\n" << std::endl;
	
	try
	{
		std::vector<int> firstVector;
		for (int i = 0; i < 200; i++)
		{
			firstVector.push_back(i);
		}
	
		std::vector<int>::iterator found;
	
		found = easyfind(firstVector, 42);
		std::cout << *found << std::endl;
	}
	catch ( std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- DEQUE ---\n" << std::endl;
	
	try
	{
		std::deque<int> firstDeque;
		for (int i = 0; i < 200; i++)
		{
			firstDeque.push_back(i);
		}
	
		std::deque<int>::iterator found;
	
		found = easyfind(firstDeque, 200);
		std::cout << *found << std::endl;
	}
	catch ( std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	
	std::cout << "\n--- LIST ---\n" << std::endl;
	try
	{
		std::list<int> firstList;
		for (int i = 0; i < 200; i++)
		{
			firstList.push_back(i);
		}
	
		std::list<int>::iterator found;
	
		found = easyfind(firstList, 45);
		std::cout << *found << std::endl;
	}
	catch ( std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

}