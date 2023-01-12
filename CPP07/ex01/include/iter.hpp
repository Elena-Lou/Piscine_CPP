/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:11:25 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/12 14:30:59 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>


template< typename T >
void iter ( T* arrayAddress, unsigned int  arraySize, void (*func)( T const & )) {

	for (unsigned int i = 0; i < arraySize; i++)
	{
		func(arrayAddress[i]);
	}
}

template< typename U>
void printElement( U const element ) {
	
	std::cout << element << std::endl;
}

#endif