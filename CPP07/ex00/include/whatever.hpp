/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:23:14 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/10 12:51:25 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <string>
#include <iostream>

template< typename T>
void swap ( T & x, T & y ) {
	
	T tmp;
	
	tmp = x;
	x = y;
	y = tmp;
}

template< typename T>
T max ( T const & x, T const y ) {
	
	if (x > y)
		return x;
	else
		return y;
}

template< typename T>
T min ( T const & x, T const y ) {
	
	if (x < y)
		return x;
	else
		return y;
}

#endif