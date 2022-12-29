/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:22:35 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/09 18:25:19 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <ctype.h>

PhoneBook::PhoneBook(void) {
    
	std::cout << "Phonebook constructor" << std::endl;
    return ;
}

void PhoneBook::display_contact(int index) const {

	std::cout << '|' << std::setfill(' ') << std::setw(9) << index;
}

void PhoneBook::display_contact(std::string data) const {

	std::cout << '|';
	if (data.size() > 10)
	{
		data.resize(9);
		data.push_back('.');
	}
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << data;
}

int	PhoneBook::ft_check_index(std::string index) {
	
	int i;

	if (!std::isdigit(index[0]) || index.size() != 1)
		return 1;
	
	i = atoi(index.c_str());
	if (this->_contact[i].get_firstname().empty())
		return 1;
	return 0;
}

void PhoneBook::get_contact(void) {

	int 		i;
	std::string	index;
	
	if (this->_contact[0].get_firstname().empty())
	{
		std::cout << "The phonebook is empty. Use ADD to add a contact" << std::endl;
		return ;
	}
	i = 0;
	while (i < 8)
	{
		if (!this->_contact[i].get_firstname().empty())
		{
			display_contact(this->_contact[i].get_index());
			display_contact(this->_contact[i].get_firstname());
			display_contact(this->_contact[i].get_lastname());
			display_contact(this->_contact[i].get_nickname());
			std::cout << '|' << std::endl;		
		}
		i++;
	}
	std::cout << "Which contact would you like to be fully diplayed ?" << std::endl;
	
	do {
		getline(std::cin, index);
		if (std::cin.eof())
 			return ;
		std::cout << "Please enter the index of a valid contact" << std::endl;
	} while (ft_check_index(index) == 1);
	i = atoi(index.c_str());
	std::cout << "INDEX : " << this->_contact[i].get_index() << "\n";
	std::cout << "FIRST NAME : " << this->_contact[i].get_firstname() << "\n";
	std::cout << "LAST NAME : " << this->_contact[i].get_lastname() << "\n";
	std::cout << "NICKNAME : " << this->_contact[i].get_nickname() << "\n";
	std::cout << "PHONE NUMBER : " << this->_contact[i].get_number() << "\n";
	std::cout << "DARKEST SECRET : " << this->_contact[i].get_secret() << "\n";
}

int PhoneBook::set_contact(int i) {
 	
	std::string	input;
	std::string prompt[] = {
		"What is your first name ?",
		"What is your last name ?",
		"What is your nickname ?",
		"What is your phone number ?",
		"What is your darkest secret ?"
	};
	
	if (i > 7)
		i = i % 8;
 	if (std::cin.eof())
 		return 1 ;
	this->_contact[i].set_index(i);
 	std::cout << this->_contact[i].get_index() << "\n";
 	
	do {
 		std::cout << prompt[0] << "\n";
 		getline(std::cin, input);
		if (std::cin.eof())
 			return 1 ;
		this->_contact[i].set_firstname(input);
 	} while (input.empty());
 	
	do {
 		std::cout << prompt[1] << "\n";
 		getline(std::cin, input);
		if (std::cin.eof())
 			return 1 ;
		this->_contact[i].set_lastname(input);
 	} while (input.empty());
 	
	do {
 		std::cout << prompt[2] << "\n";
 		getline(std::cin, input);
		if (std::cin.eof())
 			return 1 ;
		this->_contact[i].set_nickname(input);
 	} while (input.empty());
 	
	do {
 		std::cout << prompt[3] << "\n";
 		getline(std::cin, input);
		if (std::cin.eof())
 			return 1 ;
		this->_contact[i].set_number(input);
 	} while (input.empty());
 	
	do {
 		std::cout << prompt[4] << "\n";
 		getline(std::cin, input);
		if (std::cin.eof())
 			return 1 ;
		this->_contact[i].set_secret(input);
 	} while (input.empty());	
 	
	return 0;
}
    
PhoneBook::~PhoneBook(void) {

	std::cout << "Phonebook destructor" << std::endl;
    return ;
}