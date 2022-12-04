/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:58:54 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/04 14:09:31 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ScavTrap.hpp"
#include "include/ClapTrap.hpp"
#include <string>
#include <iostream>


ScavTrap::ScavTrap ( void ) : ClapTrap () {

	this->_name = "Machin";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap (std::string name) : ClapTrap ( name ) {

	std::cout << this->_name << "[class ScavTrap] is created" << std::endl;

	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	return;
}

ScavTrap::ScavTrap ( ScavTrap const & src ) : ClapTrap ( src ) {
	
	std::cout << "ScavTrap calls ClapTrap copy constructor" << std::endl;
	return ; 
}

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs ) {
	
	std::cout << "ScavTrap calls ClapTrap operator overload" << std::endl;
	ClapTrap::operator=(rhs);
	return *this;
}

void ScavTrap::attack ( const std::string& target ) {
	
	ClapTrap::attack( target );
	std::cout << "\"You, filthy mud-blood\"" << std::endl;
}

unsigned int ScavTrap::getHP ( void ) const {
	
	return this->_hitPoints;
}

unsigned int ScavTrap::getEP ( void ) const {
	
	return this->_energyPoints;
}

unsigned int ScavTrap::getAD ( void ) const {
	
	return this->_attackDamage;
}

void ScavTrap::guardGate ( void ) {

	if (this->_hitPoints == 0)
	{
		std::cout << this->_name << " is dead. " << std::endl;
		return ;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << "Gandalf did a better job, " << this->_name << std::endl;
		return ; 
	}
	std::cout << this->_name << " guards the gate : \"You shall not pass !\"" << std::endl;
	return ;
}

ScavTrap::~ScavTrap ( void ) {

	std::cout << this->_name << "[class ScavTrap] exploded" << std::endl;
	return ;
}

std::ostream & operator<<( std::ostream & out, ScavTrap const & rhs) {

	out << "HP : " << rhs.getHP() << "\n";
	out << "EP : " << rhs.getEP() << "\n";
	out << "AD : " << rhs.getAD() << std::endl;

	return out;
}