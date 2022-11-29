/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:58:54 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/29 15:57:43 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ScavTrap.hpp"
#include "include/ClapTrap.hpp"
#include <string>
#include <iostream>


ScavTrap::ScavTrap ( void ) {

	this->_name = "Machin";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap ( std::string name ) : ClapTrap ( name ) {

	std::cout << this->_name << "[class ScavTrap] is created" << std::endl;

	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	return;
}

ScavTrap::ScavTrap ( ScavTrap const & src ) : ClapTrap ( src ) {
	
	std::cout << "ScavTrap called ClapTrap copy constructor" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	return ; 
}

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs ) {
	
	std::cout << "ScavTrap called ClapTrap operator overload" << std::endl;
	ClapTrap::operator=(rhs);
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	return *this;
}

void ScavTrap::attack ( const std::string& target ) {
	
	ClapTrap::attack( target );
	std::cout << "\"You, filthy mud-blood\"" << std::endl;
}

void ScavTrap::guardGate ( void ) {

	if (this->_hitPoints == 0 || this->_energyPoints == 0)
	{
		std::cout << "Gandalf did a better job, " << this->_name << std::endl;
		return ; 
	}
	std::cout << this->_name << " : \"You shall not pass !\"" << std::endl;
	return ;
}

ScavTrap::~ScavTrap ( void ) {

	std::cout << this->_name << "[class ScavTrap] exploded" << std::endl;
	return ;
}