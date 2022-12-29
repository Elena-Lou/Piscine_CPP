/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:22:35 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/08 21:55:26 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
    
	std::cout << "Phonebook constructor" << std::endl;
    return ;
}

int is_empty(std::string first_name) {
    
	if (first_name.length() > 0)
		return 1;
	else
		return 0;
}
/*
void PhoneBook::display_contact(void) const {

	int i;
	std::string str;

	std::cout << "DISPLAY CONTACT" << std::endl;

	std::cout << this->contact[0].first_name << std::endl;
	std::cout << this->contact[1].first_name << std::endl;
	
	i = 0;
	while (i < 8)
	{
		if (is_empty(this->contact[i].first_name) == 1)
		{
			std::cout << "|" << contact[i].index << "|" << contact[i].first_name << "|" << contact[i].last_name << "|" << contact[i].nickname << "|" << std::endl;
		}
		i++;
	}
	
}
*/

int PhoneBook::set_contact(int i) {
 	
	std::string	input;
	std::string prompt[] = {"What is your first name ?",
							"What is your last name ?",
							"What is your nickname ?",
							"What is your phone number ?",
							"What is your darkest secret ?"};
	
	if (i > 7)
		i = i % 8;
 	if (std::cin.eof())
 		return 1 ;
	_contact[i].set_index(i);
 	std::cout << _contact[i].get_index() << "\n";
 	
	do {
 		std::cout << prompt[0] << "\n";
 		getline(std::cin, input);
		if (std::cin.eof())
 			return 1 ;
		_contact[i].set_firstname(input);
 	} while (input.empty());
 	
	do {
 		std::cout << prompt[1] << "\n";
 		getline(std::cin, input);
		if (std::cin.eof())
 			return 1 ;
		_contact[i].set_lastname(input);
 	} while (input.empty());
 	
	do {
 		std::cout << prompt[2] << "\n";
 		getline(std::cin, input);
		if (std::cin.eof())
 			return 1 ;
		_contact[i].set_nickname(input);
 	} while (input.empty());
 	
	do {
 		std::cout << prompt[3] << "\n";
 		getline(std::cin, input);
		if (std::cin.eof())
 			return 1 ;
		_contact[i].set_number(input);
 	} while (input.empty());
 	
	do {
 		std::cout << prompt[4] << "\n";
 		getline(std::cin, input);
		if (std::cin.eof())
 			return 1 ;
		_contact[i].set_secret(input);
 	} while (input.empty());	
 	
	return 0;
}
    
PhoneBook::~PhoneBook(void) {

	std::cout << "Phonebook destructor" << std::endl;
    return ;
}