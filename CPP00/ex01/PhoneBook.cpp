/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:22:35 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/07 19:06:58 by elouisia         ###   ########.fr       */
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

    
int PhoneBook::add_contact(int i) {
	
	if (i > 7)
		i = i % 8;
	if (is_empty(this->contact[i].first_name) == 0)
	{
		std::cout << i << std::endl;
		contact[i].set_contact(i);
		std::cout << "after set_contact" << contact[i].first_name << std::endl;
		return 0;
	}
	return 1;
}

PhoneBook::~PhoneBook(void) {

	std::cout << "Phonebook destructor" << std::endl;
    return ;
}