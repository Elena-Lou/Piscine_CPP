/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:44:03 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/12 09:59:32 by elouisia         ###   ########.fr       */
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
		std::cout << e.what() << std::endl;
	}

	Array<int> intB(10);

	try {
		std::cout << "size of intB : " << intB.getSize() << std::endl;
		std::cout << "intB[12] : " << intB[12] << std::endl;
		
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	Array<int> intC(10);

	try {
		std::cout << "size of intC : " << intC.getSize() << std::endl;
		intC.setElements(3);
		std::cout << "intC[1] : " << intC[1] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
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
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n--- CHAR ---\n" << std::endl;
	
	Array<char> charA;

	try {
		std::cout << "size of charA : " << charA.getSize() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	Array<char> charB(10);

	try {
		std::cout << "size of charB : " << charB.getSize() << std::endl;
		std::cout << "charB[12] : " << charB[12] << std::endl;
		
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	Array<char> charC(10);

	try {
		std::cout << "size of charC : " << charC.getSize() << std::endl;
		charC.setElements('a');
		std::cout << "charC[1] : " << charC[1] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
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
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n--- FLOAT ---\n" << std::endl;
	
	Array<float> floatA;

	try {
		std::cout << "size of floatA : " << floatA.getSize() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	Array<float> floatB(10);

	try {
		std::cout << "size of floatB : " << floatB.getSize() << std::endl;
		std::cout << "floatB[12] : " << floatB[12] << std::endl;
		
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	Array<float> floatC(10);

	try {
		std::cout << "size of floatC : " << floatC.getSize() << std::endl;
		floatC.setElements(42.42);
		std::cout << "floatC[1] : " << floatC[1] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
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
		std::cout << e.what() << std::endl;
	}
	
}