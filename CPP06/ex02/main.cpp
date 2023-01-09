/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:47:41 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/09 10:19:25 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic.hpp"

int main ( void ) {

	std::srand(time(NULL));
	
	Base * ptr = generate();
	if (!ptr)
		return 1;

	identify( ptr );
	std::cout << "\n --------------- \n" << std::endl;
	identify( *ptr );

	delete ptr;

	return SUCCESS;
}
