/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:24:04 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/17 11:56:58 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

class ValueNotFound : public std::exception
	{
		public:
		
			const char* what( void ) const throw() {
				return ("Value not found");
			};
	};
	
template <typename T>
typename T::iterator easyfind ( T & container, int toBeFound ) {

	typename T::iterator it;
	it = find(container.begin(), container.end(), toBeFound);
	
	if (it != container.end())
	{
		std::cout << "Found it " << std::endl;
		return (it);
	}
	else
		throw ValueNotFound();
	
}



#endif