/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:10:15 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/14 14:26:37 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact ( void ) : _firstName(""), _lastName(""), _nickname(""), _phoneNb(""), _secret("") {
	
    return ;
}

std::string Contact::get_firstname( void ) const {
	return this->_firstName;
}

std::string Contact::get_lastname( void ) const {
	return this->_lastName;
}

std::string Contact::get_nickname( void ) const {
	return this->_nickname;
}

std::string Contact::get_number( void ) const {
	return this->_phoneNb;
}

std::string Contact::get_secret( void ) const {
	return this->_secret;
}

int Contact::get_index( void ) const {
	return this->_index;
}

void Contact::set_firstname(std::string firstName) {
	_firstName.assign(firstName);
}

void Contact::set_lastname(std::string lastName) {
	_lastName.assign(lastName);
}

void Contact::set_nickname(std::string nickname) {
	_nickname.assign(nickname);
}

void Contact::set_number(std::string phoneNb) {
	_phoneNb.assign(phoneNb);
}

void Contact::set_secret(std::string secret) {
	_secret.assign(secret);
}

void Contact::set_index(int index) {
	_index = index;
}

Contact::~Contact ( void ) {

    return ;
}