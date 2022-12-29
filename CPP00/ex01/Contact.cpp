/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:10:15 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/04 14:13:58 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact (void) {
    std::cout << "constructor" << std::endl;
    return ;
}

Contact::~Contact (void) {
    std::cout << "destructor" << std::endl;
    return ;
}