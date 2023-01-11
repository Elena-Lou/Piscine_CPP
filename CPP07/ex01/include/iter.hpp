/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:11:25 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/11 13:50:01 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>


template< typename T >
void iter ( T* const & arrayAddress, unsigned int const & arraySize, void (*func)( T & )) {

	for (unsigned int i = 0; i < arraySize; i++)
	{
		func(arrayAddress[i]);
	}
}

template< typename U>
void printElement( U element ) {
	
	std::cout << element << std::endl;
}

#endif