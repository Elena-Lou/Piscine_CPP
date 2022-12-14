/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:56:21 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/04 14:35:51 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"
#include "include/FragTrap.hpp"
#include "include/ScavTrap.hpp"
#include "include/DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap ( void ) : ClapTrap ("Shiny_Machin_clap_name"), ScavTrap (), FragTrap () {

	std::cout << "[DiamonTrap] Default Constructor called" << std::endl;
	this->_energyPoints = 50;
	return ;	
}

DiamondTrap::DiamondTrap ( std::string name) : ClapTrap (name + "_clap_name"), ScavTrap ( name ), FragTrap ( name ) {

	this->_name = name;
	this->_energyPoints = 50;
	std::cout << this->_name << "[class DiamondTrap] is created" << std::endl;
	std::cout << "HP : " << this->_hitPoints;
	std::cout << " EP : " << this->_energyPoints;
	std::cout << " AD : " << this->_attackDamage << std::endl;
	return ;
}

DiamondTrap::DiamondTrap ( DiamondTrap const & src ) : ClapTrap (src._name + "_clap_name"), ScavTrap ( src ), FragTrap ( src ) {
	
	*this = src;
	std::cout << "[DiamondTrap] Copy Constructor is called, ";
	std::cout << this->_name << "[class DiamondTrap] is created" << std::endl;
	std::cout << "HP : " << this->_hitPoints;
	std::cout << " EP : " << this->_energyPoints;
	std::cout << " AD : " << this->_attackDamage << std::endl;
	return ;
}

DiamondTrap & DiamondTrap::operator=( DiamondTrap const & rhs ) {
	
	std::cout << "[DiamondTrap] operator overload" << std::endl;
	ClapTrap::operator=(rhs);
	this->_name = rhs._name;
	ClapTrap::_name = this->_name;
	ClapTrap::_name += "_clap_name";
	std::cout << "HP : " << this->_hitPoints;
	std::cout << " EP : " << this->_energyPoints;
	std::cout << " AD : " << this->_attackDamage << std::endl;
	return *this;
}

unsigned int DiamondTrap::getHP ( void ) const {
	
	return this->_hitPoints;
}

unsigned int DiamondTrap::getEP ( void ) const {
	
	return this->_energyPoints;
}

unsigned int DiamondTrap::getAD ( void ) const {
	
	return this->_attackDamage;
}

void DiamondTrap::attack ( std::string target) {

	ScavTrap::attack(target);
	return ;
}

void DiamondTrap::whoAmI ( void) {
	
	std::cout << "I am " << this->_name;
	std::cout << " son of " << ClapTrap::_name << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap ( void ) {

	std::cout << this->_name << " [class DiamondTrap] exploded" << std::endl;
	return ;
	
}

std::ostream & operator<<( std::ostream & out, DiamondTrap const & rhs) {

	out << "HP : " << rhs.getHP() << "\n";
	out << "EP : " << rhs.getEP() << "\n";
	out << "AD : " << rhs.getAD() << std::endl;

	return out;
}