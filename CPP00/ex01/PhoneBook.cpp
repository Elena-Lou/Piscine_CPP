/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:22:35 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/04 15:24:17 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
    std::cout << "Phonebook constructor" << std::endl;
    return ;
}

PhoneBook::~PhoneBook(void) {
    std::cout << "Phonebook destructor" << std::endl;
    return ;
}