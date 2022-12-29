/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:14:19 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/04 15:26:52 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
	
	PhoneBook Phonebook;
	Contact	Contact;
	std::string input;
	std::string add;
	
while (1)
{
	std::cout << "Type a command" << "\n";
	getline(std::cin, input);
	if (input == "ADD")
	{		
		std::cout << "What is your first name ?" << "\n";
		getline(std::cin, Contact.first_name);
		std::cout << "What is your last name ?" << "\n";
		getline(std::cin, Contact.last_name);
		std::cout << "What is your nickname ?" << "\n";
		getline(std::cin, Contact.nickname);
		std::cout << "What is your darkest secret ?" << "\n";
		getline(std::cin, Contact.secret);
		std::cout << Contact.first_name << "-" << Contact.last_name << "\n"; 
	
	}
	else if (input == "EXIT")
		return 0;
	else
		std::cout << "Nope !" << std::endl;
}
	
}