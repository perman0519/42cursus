# pragma once

#include <vector>
#include <map>
#include "Account.hpp"
using namespace std;

class Bank {
    static int _accountIndex; 
    int _liquidity; // total amount of money in the bank
    vector<Account *> clientAccounts;
    map<int, double> loans;

public:
    Bank(int liquidity = 0);
    ~Bank();

    void createAccount(int value);
    void deleteAccount(int id);
    void displayAccounts() const;

    void deposit(int id, double amount); // 입금
    void withdraw(int id, double amount); // 출금
    void Loans(int id, double amount); // 대출
    void displayLoansList() const;
};