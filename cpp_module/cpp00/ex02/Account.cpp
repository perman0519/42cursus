/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:13:03 by junssong          #+#    #+#             */
/*   Updated: 2024/02/20 16:55:24 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//public static
int	Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
    return _totalAmount;
}

int	Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
        << ";total:" << _totalAmount
        << ";deposits:" << _totalNbDeposits
        << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

//construct
Account::Account( int initial_deposit ) {
    this->_amount = initial_deposit;
    this->_nbAccounts++;
    this->_accountIndex = this->_nbAccounts - 1;
    this->_totalAmount += this->_amount;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
        << ";amount:" << _amount
        << ";created" << std::endl;
}

Account::~Account( void ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
        << ";amount:" << _amount
        << ";closed" << std::endl;
}

Account::Account( void ) {

}

//public
void	Account::makeDeposit( int deposit ) {
    int p_amount = _amount;
    _amount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
        << ";p_amount:" << p_amount
        << ";deposit:" << deposit
        << ";amount:" << _amount
        << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
        << ";p_amount:" << _amount
        << ";withdrawal:";
    if (_amount <= withdrawal)
    {
        std::cout << "refused" <<std::endl;
        return false;
    }
    else
    {
        this->_amount -= withdrawal;
        this->_nbWithdrawals++;
        this->_totalNbWithdrawals++;
        this->_totalAmount -= withdrawal;
        std::cout << withdrawal
            << ";amount:" << _amount
            << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    }
}

int		Account::checkAmount( void ) const {
    return 0;
}

void	Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex \
        << ";amount:" << _amount
        << ";deposits:" << _nbDeposits \
        << ";withdrawals:" << _nbWithdrawals << std::endl;
}

//private static
void	Account::_displayTimestamp( void ) {
    // 현재 시간을 얻기 위한 시간 정보 구조체 생성
    std::tm *currentTime;
    std::time_t t;

    // 시스템 시간 얻기
    std::time(&t);

    // 시간 정보 구조체로 변환
    currentTime = std::localtime(&t);

    // 형식을 지정하여 출력
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", currentTime);

    std::cout << buffer;
    std::cout.flush();
}
