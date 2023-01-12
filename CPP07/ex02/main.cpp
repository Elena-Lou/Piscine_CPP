/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:44:03 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/12 14:36:53 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main ( void ) {

	std::cout << "\n--- INT ---\n" << std::endl;

	Array<int> intA;

	try {
		std::cout << "size of intA : " << intA.getSize() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	Array<int> intB(10);

	try {
		std::cout << "size of intB : " << intB.getSize() << std::endl;
		std::cout << "intB[12] : " << intB[12] << std::endl;
		
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	Array<int> intC(10);

	try {
		std::cout << "size of intC : " << intC.getSize() << std::endl;
		intC.setElements(3);
		std::cout << "intC[1] : " << intC[1] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	Array<int> intD(intC);
	
	try {
	std::cout << "intD[1] : " << intD[1] << std::endl;
		intD.setElements(5);
		std::cout << "intD[1] : " << intD[1] << std::endl;
		std::cout << "intC[1] : " << intC[1] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- CHAR ---\n" << std::endl;
	
	Array<char> charA;

	try {
		std::cout << "size of charA : " << charA.getSize() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	Array<char> charB(10);

	try {
		std::cout << "size of charB : " << charB.getSize() << std::endl;
		std::cout << "charB[12] : " << charB[12] << std::endl;
		
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	Array<char> charC(10);

	try {
		std::cout << "size of charC : " << charC.getSize() << std::endl;
		charC.setElements('a');
		std::cout << "charC[1] : " << charC[1] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	Array<char> charD(charC);
	
	try {
	std::cout << "charD[1] : " << charD[1] << std::endl;
		charD.setElements('w');
		std::cout << "charD[1] : " << charD[1] << std::endl;
		std::cout << "charC[1] : " << charC[1] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- FLOAT ---\n" << std::endl;
	
	Array<float> floatA;

	try {
		std::cout << "size of floatA : " << floatA.getSize() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	Array<float> floatB(10);

	try {
		std::cout << "size of floatB : " << floatB.getSize() << std::endl;
		std::cout << "floatB[12] : " << floatB[12] << std::endl;
		
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	Array<float> floatC(10);

	try {
		std::cout << "size of floatC : " << floatC.getSize() << std::endl;
		floatC.setElements(42.42);
		std::cout << "floatC[1] : " << floatC[1] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	Array<float> floatD(floatC);
	
	try {
	std::cout << "floatD[1] : " << floatD[1] << std::endl;
		floatD.setElements(3.14);
		std::cout << "floatD[1] : " << floatD[1] << std::endl;
		std::cout << "floatC[1] : " << floatC[1] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << " array tests " << std::endl;
	
	Array<int> numbers(1);
	Array<int> n(18);

	std::cout << numbers.getSize() << std::endl;

	numbers = n;
	std::cout << numbers.getSize() << std::endl;
	(void)numbers;
}

// #include <iostream>
// #include <Array.hpp>
// #include <cstdlib>
// #include <time.h>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }