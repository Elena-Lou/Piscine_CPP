/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:51:26 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/29 16:15:35 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/FragTrap.hpp"
#include "include/ClapTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap ( void ) {
	
	this->_name = "Machin";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Default Constructor called" << std::endl;
	return;
}

FragTrap::FragTrap ( std::string name ) : ClapTrap ( name ) {
	
	std::cout << this->_name << "[class FragTrap] is created" << std::endl;

	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	return;
}

FragTrap::FragTrap ( FragTrap const & src ) : ClapTrap ( src ) {

	std::cout << "FragTrap called ClapTrap copy constructor" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	return ;
}

FragTrap & FragTrap::operator=( FragTrap const & rhs ) {
	
	std::cout << "FragTrap called operator overload" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = 100;
		this->_attackDamage = 30;
		this->_energyPoints = 100;
	}
	return *this;
}

void FragTrap::highFiveGuys ( void ) {

	if (this->_hitPoints == 0 || this->_energyPoints == 0)
	{
		std::cout << "Aaaaaaaarrrrrrggghhhh don't leave me hangin'...!" << std::endl;
		return ; 
	}
	else
	{
		std::cout << "\"C'mon ! Give me five !!\"" << std::endl;
		return ;
	}
		
}

FragTrap::~FragTrap ( void ) {
	
	std::cout << this->_name << "[class FragTrap] exploded" << std::endl;
	return ;
	
}

