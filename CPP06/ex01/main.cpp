/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:06:14 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/08 19:56:55 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.h"

uintptr_t serialize( Data* ptr ) {
	
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize( uintptr_t ptr ) {
	
	return reinterpret_cast<Data *>(ptr);
}

int	main ( int ac, char** av ) {

	if (ac != 2)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return 1;
	}
	Data*		ptr = new Data;
	ptr->input = av[1];
	
	uintptr_t	serialized = serialize(ptr);
	
	Data*		deserialized = deserialize(serialized);

	std::cout << "ptr : " << ptr << " - ptr->input : " << ptr->input << std::endl;
	std::cout << "serialized : " << serialized << std::endl;
	std::cout << "deserialized : " << deserialized << " - deserialized->input : " << deserialized->input << std::endl;

	delete ptr;
	return 0;
}