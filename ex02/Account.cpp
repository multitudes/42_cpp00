/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:04:03 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/02 10:51:55 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>


/**
 * @brief Default constructor for the Account class.
 * 
 * Initializes all member variables to their default values.
 * they are private but because are declared as static 
 * it is correct to initialize them outside the class
 * definition because static members are shared among all objects of the class.
 */
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/**
 * @brief Parameterized constructor for the Account class.
 * 
 * @param initial_deposit The initial deposit for the account.
 */
Account::Account(int initial_deposit)
: _accountIndex(_nbAccounts),  _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;

}

/**
 * @brief Default constructor for the Account class.
 * 
 */
Account::Account() : _accountIndex(_nbAccounts), _amount(0), _nbDeposits(0), _nbWithdrawals(0) {
    _nbAccounts++;	
}

Account::~Account() {
	_nbAccounts--;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

/**
 * @brief Function to get the number of accounts.
 * 
 * @return int The number of accounts.
 */
int Account::getNbAccounts() {
	return _nbAccounts;
}

/**
 * @brief Function to get the total amount of all accounts.
 */
int Account::getTotalAmount() {
	return _totalAmount;
}

/**
 * @brief Function to get the number of deposits.
 * 
 * @return int The number of deposits.
 */
int Account::getNbDeposits() {
	return _totalNbDeposits;
}

/**
 * @brief Function to get the number of withdrawals.
 */
int Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

/**
 * @brief Function to display the account information.
 *
 * this will print the summary of all accounts
 * like  accounts:8;total:12442;deposits:8;withdrawals:6
 */
void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

/**
 * @brief Function to make a deposit to the account.
 * 
 * @param deposit The amount to deposit.
 */
void Account::makeDeposit(int deposit) {
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl; 
}

/**
 * @brief Function to make a withdrawal from the account.
 * 
 * @param withdrawal The amount to withdraw.
 * @return true If the withdrawal was successful.
 */
bool Account::makeWithdrawal(int withdrawal) {
	if (_amount - withdrawal >= 0)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		_displayTimestamp();
		std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	}
	else
	{
		_displayTimestamp();
		std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;	
		return false;
	}
}

/**
 * @brief Function to check the amount in the account.
 * 
 * @return int The amount in the account.
 */
int Account::checkAmount() const {
	return _amount;
}

/**
 * @brief Function to display the account status.
 */
void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

/**
 * @brief Function to display the timestamp.
 */
void Account::_displayTimestamp() {
	std::time_t now = std::time(0);
	char timestamp[20];
	std::strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S]", std::localtime(&now));
	std::cout << timestamp;
}