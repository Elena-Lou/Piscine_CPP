/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:22:35 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/12 12:32:38 by elouisia         ###   ########.fr       */
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
    
    return ;
}

void PhoneBook::display_contact(int index) const {

	std::cout << '|' << std::setw(9) << std::right << index;
}

void PhoneBook::display_contact(std::string data) const {

	std::cout << '|';
	if (data.size() > 10)
	{
		data.resize(9);
		data.push_back('.');
	}
	std::cout << std::setw(10) << std::right << data;
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
	std::cout << std::setw(15) << std::left << "INDEX " << ": ";
	std::cout << this->_contact[i].get_index() << "\n";
	std::cout << std::setw(15) << std::left << "FIRST NAME " << ": ";
	std::cout << this->_contact[i].get_firstname() << "\n";
	std::cout << std::setw(15) << std::left << "LAST NAME " << ": ";
	std::cout << this->_contact[i].get_lastname() << "\n";
	std::cout << std::setw(15) << std::left << "NICKNAME " << ": ";
	std::cout << this->_contact[i].get_nickname() << "\n";
	std::cout << std::setw(15) << std::left << "PHONE NUMBER " << ": ";
	std::cout << this->_contact[i].get_number() << "\n";
	std::cout << std::setw(15) << std::left << "DARKEST SECRET " << ": ";
	std::cout << this->_contact[i].get_secret() << "\n";
}

int PhoneBook::set_contact(int i) {
 	
	int 		j;
	std::string	input;
	std::string prompt[] = {
		"What is the contact's first name ?",
		"What is the contact's last name ?",
		"What is the contact's nickname ?",
		"What is the contact's phone number ?",
		"What is the contact's darkest secret ?"
	};
	void (Contact::*answer[])(std::string) = {
		&Contact::set_firstname,
		&Contact::set_lastname,
		&Contact::set_nickname,
		&Contact::set_number,
		&Contact::set_secret
	};
	
	if (i > 7)
		i = i % 8;
 	if (std::cin.eof())
 		return 1 ;
	this->_contact[i].set_index(i);
 	
	j = 0;
	while (j < 5)
	{
		do {
 			std::cout << prompt[j] << "\n";
 			getline(std::cin, input);
			if (std::cin.eof())
 				return 1 ;
			(_contact[i].*(answer[j]))(input);
 		} while (input.empty());
		j++;
	}
	return 0;
}
    
PhoneBook::~PhoneBook(void) {

    return ;
}