/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:14:19 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/08 22:30:10 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
	
	PhoneBook phonebook;
	std::string input;
	int	i;

	i = 0;	
	while (1)
	{
		if (std::cin.eof())
			return 1;
		std::cout << "Type a command" << "\n";
		getline(std::cin, input);
		if (input == "ADD")
		{
			if (phonebook.set_contact(i) == 0)
				i++;
		}
		else if (input == "SEARCH")
			phonebook.get_contact();
		else if (input == "EXIT")
			return 0;
	}
}