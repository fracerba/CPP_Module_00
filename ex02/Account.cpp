#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account(int initial_deposit)
{
	static int i = 0;

	this->_amount = initial_deposit;
	this->_accountIndex = i;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	if (i == 0)
	{
		_nbAccounts = 0;
		_totalAmount = 0;
		_totalNbDeposits = 0;
		_totalNbWithdrawals = 0;
	}
	_nbAccounts = ++i;
	_totalAmount += this->_amount;
	_totalNbDeposits += this->_nbDeposits;
	_totalNbWithdrawals += this->_nbWithdrawals;
	_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";";
	std::cout<<"amount:"<<this->_amount<<";created\n";
}

Account::~Account()
{
	_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";";
	std::cout<<"amount:"<<this->_amount<<";closed\n";
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";";
	std::cout<<"p_amount:"<<this->_amount<<";";
	if(deposit <= 0)
	{
		std::cout<<"deposit:refused\n";
		return;
	}
	std::cout<<"deposit:"<<deposit<<";";
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout<<"amount:"<<this->_amount<<";";
	std::cout<<"nb_deposits:"<<this->_nbDeposits<<"\n";
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";";
	std::cout<<"p_amount:"<<this->_amount<<";";
	if(this->_amount < withdrawal || withdrawal <= 0)
	{
		std::cout<<"withdrawal:refused\n";
		return(false);
	}
	std::cout<<"withdrawal:"<<withdrawal<<";";
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout<<"amount:"<<this->_amount<<";";
	std::cout<<"nb_withdrawals:"<<this->_nbWithdrawals<<"\n";
	return(true);
}

int		Account::checkAmount( void ) const
{
	_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";";
	std::cout<<"amount:"<<this->_amount<<"\n";
	return(this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";";
	std::cout<<"amount:"<<this->_amount<<";";
	std::cout<<"deposits:"<<this->_nbDeposits<<";";
	std::cout<<"withdrawals:"<<this->_nbWithdrawals<<"\n";
}

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout<<"accounts:"<<Account::getNbAccounts()<<";";
	std::cout<<"total:"<<Account::getTotalAmount()<<";";
	std::cout<<"deposits:"<<Account::getNbDeposits()<<";";
	std::cout<<"withdrawals:"<<Account::getNbWithdrawals()<<"\n";
}

void	Account::_displayTimestamp()
{
	time_t now = time(0);
	std::string dt = ctime(&now);
	std::cout<<"["<<dt.substr(20, 4);
	if(dt.substr(4, 3) == "Jan")
		std::cout<<"01";
	else if(dt.substr(4, 3) == "Feb")
		std::cout<<"02";
	else if(dt.substr(4, 3) == "Mar")
		std::cout<<"03";
	else if(dt.substr(4, 3) == "Apr")
		std::cout<<"04";
	else if(dt.substr(4, 3) == "May")
		std::cout<<"05";
	else if(dt.substr(4, 3) == "Jun")
		std::cout<<"06";
	else if(dt.substr(4, 3) == "Jul")
		std::cout<<"07";
	else if(dt.substr(4, 3) == "Aug")
		std::cout<<"08";
	else if(dt.substr(4, 3) == "Sep")
		std::cout<<"09";
	else if(dt.substr(4, 3) == "Oct")
		std::cout<<"10";
	else if(dt.substr(4, 3) == "Nov")
		std::cout<<"11";
	else if(dt.substr(4, 3) == "Dec")
		std::cout<<"12";
	std::cout<<dt.substr(8, 2)<<"_"<<dt.substr(11, 2);
	std::cout<<dt.substr(14, 2)<<dt.substr(17, 2)<<"] ";
}