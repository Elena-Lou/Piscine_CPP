/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:04:04 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/17 10:02:02 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

/* A stack is a container with a First In Last Out structure with an underlying container
- by default a deque, but can be any of the other Sequence containers : vector or list. 
The stack only possesses a limited number of methods but the underlying container's methods are
accessible. 
/!\ the stack pushes and pops the elements from its top, which actually is the back
of the underlying container */

template < typename T>
class MutantStack : public std::stack<T>
{

public:

	MutantStack( void ) {
		
		std::cout << "[MutantStack] Default Constructor" << std::endl;
	};
	
	~MutantStack( void ) {

		std::cout << "[MutantStack] Destructor" << std::endl;
	};
	
	MutantStack ( MutantStack<T> const & src ) {
		std::cout << "[MutantStack] Copy Constructor" << std::endl;

		*this = src;
	}

	MutantStack<T> & operator=( MutantStack<T> const & rhs ) {

		std::cout << "Operator = Overload" << std::endl;

		if (this != &rhs)
		{
			this->c = rhs.c;
		}
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin() {
		
		return this->c.begin();
	}

	iterator end() {

		return this->c.end();
	}

	
};

#endif