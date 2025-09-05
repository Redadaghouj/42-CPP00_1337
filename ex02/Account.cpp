#include <ctime>
#include <iostream>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int inital_deposit) :
	_accountIndex(_nbAccounts),
	_amount(inital_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += inital_deposit;
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex
	<< ";amount:" << checkAmount()
	<< ";created" << std::endl;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout
	<< "accounts:" << Account::getNbAccounts()
	<< ";total:" << Account::getTotalAmount()
	<< ";deposits:" << Account::getNbDeposits()
	<< ";withdrawals:" << Account::getNbWithdrawals()
	<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex
	<< ";p_amount:" << checkAmount()
	<< ";deposit:" << deposit
	<< ";amount:" << (_amount += deposit)
	<< ";nb_deposits:" << _nbDeposits
	<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex
	<< ";p_amount:" << checkAmount()
	<< ";withdrawal:";
	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	else
	{
		_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		std::cout
		<< withdrawal
		<< ";amount:" << (_amount -= withdrawal)
		<< ";nb_withdrawals:" << _nbWithdrawals
		<< std::endl;
		return (true);
	}
}

int Account::checkAmount() const
{
	return (_amount);
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex
	<< ";amount:" << checkAmount()
	<< ";deposits:" << _nbDeposits
	<< ";withdrawals:" << _nbWithdrawals
	<< std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex
	<< ";amount:" << checkAmount()
	<< ";closed" << std::endl;
}

void Account::_displayTimestamp()
{
	time_t now;
	struct tm *timeInfo;

	time(&now);
	timeInfo = localtime(&now);
	std::cout
	<< "["
	<< (timeInfo->tm_year + 1900)
	<< std::setfill('0')
	<< std::setw(2) << (timeInfo->tm_mon + 1)
	<< std::setw(2) << timeInfo->tm_mday
	<< "_"
	<< std::setw(2) << timeInfo->tm_hour
	<< std::setw(2) << timeInfo->tm_min
	<< std::setw(2) << timeInfo->tm_sec
	<< "] ";
}

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}
