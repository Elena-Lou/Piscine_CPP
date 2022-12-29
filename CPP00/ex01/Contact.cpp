/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:10:15 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/10 17:24:57 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact (void) {

    return ;
}

std::string Contact::get_firstname(void) const {
	return this->_first_name;
}

std::string Contact::get_lastname(void) const {
	return this->_last_name;
}

std::string Contact::get_nickname(void) const {
	return this->_nickname;
}

std::string Contact::get_number(void) const {
	return this->_phone_nb;
}

std::string Contact::get_secret(void) const {
	return this->_secret;
}

int Contact::get_index(void) const {
	return this->_index;
}

void Contact::set_firstname(std::string first_name) {
	_first_name.assign(first_name);
}

void Contact::set_lastname(std::string last_name) {
	_last_name.assign(last_name);
}

void Contact::set_nickname(std::string nickname) {
	_nickname.assign(nickname);
}

void Contact::set_number(std::string phone_nb) {
	_phone_nb.assign(phone_nb);
}

void Contact::set_secret(std::string secret) {
	_secret.assign(secret);
}

void Contact::set_index(int index) {
	_index = index;
}

Contact::~Contact (void) {

    return ;
}