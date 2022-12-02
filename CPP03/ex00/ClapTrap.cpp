/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:20:15 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/04 12:33:23 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap ( void ) : _name("Machin"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {

	std::cout << "Default Constructor" << std::endl;
	return ;
}

ClapTrap::ClapTrap ( std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	
	std::cout << "Constructor is called" << std::endl;
	return ;
}

ClapTrap::ClapTrap ( ClapTrap const & src) {
	
	std::cout << "Copy Constructor is called" << std::endl;
	*this = src;
	return ;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & rhs ) {
	
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

std::string ClapTrap::getName ( void ) const {

	return this->_name;
}

ClapTrap::~ClapTrap ( void ) {

	std::cout << "Destructor is called" << std::endl;
	return ;
}

void ClapTrap::attack ( const std::string& target ) {
	
	if (this->_hitPoints == 0)
	{
		std::cout << this->_name << " is dead. " << std::endl;
		return ;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << this->_name << " is exhausted." << std::endl;
		return ;
	}
	else
	{
		std::cout << this->_name;
		std::cout << " attacks " << target;
		std::cout << ", causing " << this->_attackDamage;
		std::cout << " points of damage !" << std::endl;
		this->_energyPoints -= 1;
	}
}

void ClapTrap::beRepaired ( unsigned int amount ) {
	
		if (this->_hitPoints == 0)
		{
			std::cout << this->_name << " is dead. " << std::endl;
			return ;
		}
		else if (this->_energyPoints == 0)
		{
			std::cout << this->_name << " is exhausted." << std::endl;
			return ;
		}
		else
		{
		std::cout << this->_name  << " regains " << amount << " hit points" << std::endl;
		this->_hitPoints += amount;
		std::cout << this->_name  << " now has " << this->_hitPoints << " hit points" << std::endl;
		this->_energyPoints -= 1;		
		}
}

void ClapTrap::takeDamage ( unsigned int amount ) {
	
		std::cout << this->_name  << " takes " << amount << " attack damage" << std::endl;
		this->_hitPoints -= amount;
		std::cout << this->_name  << " now has " << this->_hitPoints << " hit points" << std::endl;
		if (this->_hitPoints == 0)
		{
			std::cout << this->_name << " is dead. " << std::endl;
			return ;
		}
			
}

std::ostream & operator<<( std::ostream & out, ClapTrap const & rhs ) {
	
	out << rhs.getName();
	return out;
}