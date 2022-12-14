/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:11:11 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/12 14:32:31 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main ( void ) {

	unsigned int size;
	std::srand(time(NULL));
	
	std::cout << "--- Test with int ---" << std::endl;
	std::cout << "Please enter a size : " << std::endl;
	std::cin >> size;
	
	int* array = new int[size];
	for (unsigned int i = 0; i < size; i++)
	{
		int random = std::rand() % 100;
		array[i] = random;
	}

	std::cout << "iter() : " << std::endl;
	iter(array, size, &printElement);
	delete [] array;

	std::cout << "--- Test with char ---" << std::endl;
	std::cout << "Please enter a size between 1 and 26 : " << std::endl;
	std::cin >> size;
	
	char* arrayChar = new char[size];
	for (unsigned int i = 0; i < size; i++)
	{
		arrayChar[i] = i + 65;
		
	}

	std::cout << "iter() : " << std::endl;
	iter(arrayChar, size, &printElement);\
	delete [] arrayChar;


	std::cout << "--- Test with string ---" << std::endl;
	std::cout << "Please enter a size : " << std::endl;
	std::cin >> size;

	std::string string;
	std::cout << "Please enter a word : " << std::endl;
	std::cin.ignore();
	getline(std::cin, string);
	
	std::string* arrayString = new std::string[size];
	for (unsigned int i = 0; i < size; i++)
	{
		arrayString[i] = string;
	}
	std::cout << "iter() : " << std::endl;
	iter(arrayString, size, &printElement);
	delete [] arrayString;
}

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

// template< typename T >
// void print( T const & x ) { std::cout << x << std::endl; return; }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };  // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
//   Awesome tab2[5];

//   iter( tab, 5, print<int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }