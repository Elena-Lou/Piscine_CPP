/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:51:26 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/04 14:12:50 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/FragTrap.hpp"
#include "include/ClapTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap ( void ) : ClapTrap () {
	
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

	std::cout << "FragTrap calls ClapTrap copy constructor" << std::endl;

	return ;
}

FragTrap & FragTrap::operator=( FragTrap const & rhs ) {
	
	std::cout << "FragTrap calls operator overload" << std::endl;
	ClapTrap::operator=(rhs);
	return *this;
}

unsigned int FragTrap::getHP ( void ) const {
	
	return this->_hitPoints;
}

unsigned int FragTrap::getEP ( void ) const {
	
	return this->_energyPoints;
}

unsigned int FragTrap::getAD ( void ) const {
	
	return this->_attackDamage;
}

void FragTrap::highFiveGuys ( void ) {

	if (this->_hitPoints == 0)
	{
		std::cout << this->_name << " is dead. " << std::endl;
		return ;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << "AAAAARRRRrrrrrggggggghhh don't leave me hangin'...!" << std::endl;
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

std::ostream & operator<<( std::ostream & out, FragTrap const & rhs) {

	out << "HP : " << rhs.getHP() << "\n";
	out << "EP : " << rhs.getEP() << "\n";
	out << "AD : " << rhs.getAD() << std::endl;

	return out;
}

