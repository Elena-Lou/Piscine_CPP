/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Arg.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:53:04 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/29 18:28:39 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Arg.hpp"

Arg::Arg ( void ) {

	std::cout << "[Arg Class] Constructor" << std::endl;
	return ;
}

Arg::~Arg ( void ) {

	std::cout << "[Arg Class] Destructor" << std::endl;
	return ;
}

void Arg::setValue ( char* value ) {
	
	this->_value = value;
}