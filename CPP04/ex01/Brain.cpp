/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:49:08 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/04 15:55:18 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <string>
#include <iostream>

Brain::Brain ( void ) {
	
	std::cout << "[Brain class] Default Constructor" << std::endl;
	return ;
}

Brain::~Brain ( void ) {

	std::cout << "[Brain class] Default Destructor" << std::endl;
	return ;
}