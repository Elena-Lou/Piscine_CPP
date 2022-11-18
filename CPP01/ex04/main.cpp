/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:43:47 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/21 16:22:36 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int main( int ac, char **av ) {
	
	(void)av;
	if (ac != 4)
	{
		std::cout << "Usage: ./sed filename string_to_be_replaced string_to_replace" << std::endl;
		return 0;
	}
	std::string 	line;
	std::string		token;
	std::string 	viserys = av[2];
	std::string 	rhaenyra = av[3];
	std::ifstream 	infile;
	std::ofstream 	outfile;
	std::string 	outfileName;
	std::size_t 	strIndex;
	

	infile.open(av[1], std::ifstream::in);
	outfileName = av[1];
	outfileName += ".replace";
	outfile.open(outfileName.c_str(), std::ofstream::out | std::ofstream::trunc);
		while (getline(infile, line))
		{
			strIndex = 0;
			do {
				strIndex = line.find(viserys, strIndex);
				if (strIndex != std::string::npos)
				{
					line.erase(strIndex, viserys.length());
					std::cout << strIndex << std::endl;
					line.insert(strIndex, rhaenyra);
				}
			} while (strIndex != std::string::npos);
			outfile << line << std::endl;
		}
	infile.close();
	outfile.close();
	return 0;
	
	
}