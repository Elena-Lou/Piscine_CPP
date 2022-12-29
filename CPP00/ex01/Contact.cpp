/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:10:15 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/07 19:11:09 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact (void) {
    std::cout << "Contact constructor" << std::endl;
    return ;
}

int Contact::set_contact(int i) {
	std::string prompt[] = {"What is your first name ?", "What is your last name ?", "What is your nickname ?", "What is your phone number ?", "What is your darkest secret ?"};
	std::string answer[] = {this->first_name, this->last_name, this->nickname, this->phone_nb, this->secret};

	if (std::cin.eof())
		return 1 ;
        this->index = i % 8;
		std::cout << this->index << "\n";
		do {
			std::cout << prompt[0] << "\n";
			getline(std::cin, this->first_name);
		} while (this->first_name.length() < 1);
		do {
			std::cout << prompt[1] << "\n";
			getline(std::cin, this->last_name);
		} while (this->last_name.length() < 1);
		do {
			std::cout << prompt[2] << "\n";
			getline(std::cin, this->nickname);
		} while (this->nickname.length() < 1);
		do {
			std::cout << prompt[3] << "\n";
			getline(std::cin, this->phone_nb);
		} while (this->phone_nb.length() < 1);
		do {
			std::cout << prompt[4] << "\n";
			getline(std::cin, this->secret);
		} while (this->secret.length() < 1);	
		return 0;
}

Contact::~Contact (void) {
    std::cout << "Contact destructor" << std::endl;
    return ;
}