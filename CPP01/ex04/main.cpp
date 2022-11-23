/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:43:47 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/23 09:28:55 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int main( int ac, char **av ) {

	if (ac != 4)
	{
		std::cerr << "Usage: ./sed filename string_to_be_replaced string_to_replace" << std::endl;
		return 1;
	}
	std::string 	line;
	std::string 	viserys = av[2];
	std::string 	rhaenyra = av[3];
	std::string 	outfileName;
	std::size_t 	strIndex;
	
	std::ifstream 	infile;
	std::ofstream 	outfile;

	if (viserys.empty())
	{
		std::cerr << "Invalid arguments" << std::endl;
		return 1;
	}
	
	infile.open(av[1], std::ifstream::in);
	if (!infile)
	{
		std::cerr << "Open error" << std::endl;
		return 1;
	}
	
	outfileName = av[1];
	outfileName += ".replace";
	
	outfile.open(outfileName.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!outfile)
	{
		std::cerr << "Open error" << std::endl;
		return 1;
	}
	while (getline(infile, line))
	{
		strIndex = 0;
		do {
			strIndex = line.find(viserys, strIndex);
			if (strIndex != std::string::npos)
			{
				line.erase(strIndex, viserys.length());
				line.insert(strIndex, rhaenyra);
				strIndex += rhaenyra.length();
			}
		} while (strIndex != std::string::npos);
		outfile << line << std::endl;
	}
	infile.close();
	outfile.close();
	return 0;
	
	
}