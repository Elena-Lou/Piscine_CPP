/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:23:02 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/15 17:46:20 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main ( void ) {
	
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;
	
	std::cout << "address of str : " << &str << std::endl;
	std::cout << "address of stringPTR : " << stringPTR << std::endl;
	std::cout << "address of stringREF : " << &stringREF << std::endl;
	
	std::cout << "str : " << str << std::endl;
	std::cout << "stringPTR : " << *stringPTR << std::endl;
	std::cout << "stringREF : " << stringREF << std::endl;
	
	return 0;
}