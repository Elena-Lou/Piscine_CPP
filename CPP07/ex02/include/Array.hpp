/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:44:12 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/11 17:06:24 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <iostream>
#include <string>

template< typename T >
class Array
{

private:

	unsigned int _n;
	T*			_array;
	
public:
	
	Array( void ) : _n(0){

		this->_array = NULL;
		std::cout << "[Array] Default Constructor" << std::endl;
	};
	
	Array( unsigned int n ) : _n(n) {
		
		this->_array = new T[n];
		std::cout << "[Array] Constructor" << std::endl;
	};
	
	~Array( void ) {

		if (this->_array != NULL)
			delete [] this->_array;
		std::cout << "[Array] Destructor" << std::endl;
	};
	
	Array( Array const & src ) {
		
		std::cout << "[Array] Copy Constructor" << std::endl;
		this->_n = src._n;
		this->_array = new T[*src._array];
		for (unsigned int i = 0; i < src._n; i++)
		{
			this->_array[i] = src._array[i];
		}
	};

	Array & operator=( Array const & rhs ) {
		
		std::cout << "Operator overload" << std::endl;
		if (this != &rhs)
		{
			this->_n = rhs._n;
			if (this->_array != NULL)
			{
				*(this->_array) = *(rhs._array);
				for (unsigned int i; i < rhs._n; i++)
				{
					std::cout << rhs._array[i] << std::endl;
					this->_array[i] = rhs._array[i];
				}
			}
		}
		return *this;
	};

	void getSize( void ) const {

		return this->_n;
	};

	void setElements ( T element) {
		for (unsigned int i = 0; i < this->_n; i++)
		{
			this->_array[i] = element;
		}
	};

	T & getElement ( unsigned int index ) const {
		
		if (index > 0 && index < this->_n)
				return this->_array[index];
		else
			throw Array::InvalidIndex();

	};
	
	
	class InvalidIndex : public std::exception
	{
		public:
		
			const char* what( void ) const throw() {
				return ("Invalid Index");
			};
	};

};



#endif