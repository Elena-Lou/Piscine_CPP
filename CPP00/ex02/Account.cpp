/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:13:10 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/12 16:59:54 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp ( void ) {

	time_t now = time(0);
	tm *ltm = localtime(&now);
	
	std::cout << '[' << 1900 + ltm->tm_year;
	std::cout << 1 + ltm->tm_mon;
	std::cout << ltm->tm_mday << '_';
	std::cout << ltm->tm_hour;
	std::cout << ltm->tm_min;
	std::cout << ltm->tm_sec << "] ";
}

Account::Account (int deposit) {

	_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts += 1;
	this->_amount = deposit;
	Account::_totalAmount += deposit;
	std::cout << "index:" << this->_accountIndex << ";amount:" << deposit << ";created" << std::endl;
	return ;
}

int Account::getNbAccounts (void) {
	return Account::_nbAccounts;
}

int Account::getTotalAmount (void) {
	return Account::_totalAmount;
}

int Account::getNbDeposits (void) {
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals (void) {
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos (void) {
	
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout <<  ";total:" << getTotalAmount();
	std::cout << ";deposit:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit (int deposit) {
	
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
	
}

bool Account::makeWithdrawal (int withdrawal) {
	
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (withdrawal > this->_amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return 1;
	}
	std::cout << ";withdrawal:" << withdrawal;
	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;
	Account::_totalNbWithdrawals += 1;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return 0;
}

int Account::checkAmount (void) const {
	std::cout << "CHECK AMOUNT" << std::endl;
	return 0;
}

void Account::displayStatus (void) const {

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

Account::~Account (void) {

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed;" << std::endl;
	return ;
}