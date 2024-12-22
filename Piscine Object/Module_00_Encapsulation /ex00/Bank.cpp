#include "Bank.hpp"
#include <iostream>
using namespace std;

int Bank::_accountIndex = 0;

Bank::Bank(int liquidity) : _liquidity(liquidity) {}

Bank::~Bank() {
    for (int i = 0; i < (int)clientAccounts.size(); i++) {
        delete clientAccounts[i];
    }
}

void Bank::createAccount(int value) {
    double v = value * 0.95;
    clientAccounts.push_back(new Account(v, _accountIndex++));
    _liquidity += value;
}

void Bank::deleteAccount(int id) {
    for (int i = 0; i < (int)clientAccounts.size(); i++) {
        if (clientAccounts[i]->getId() == id) {
            _liquidity -= clientAccounts[i]->getValue();
            delete clientAccounts[i];
            clientAccounts.erase(clientAccounts.begin() + i);
            return;
        }
    }
}

void Bank::displayAccounts() const {
    cout << "--------------------------------" << endl;
    cout << "Bank liquidity: " << _liquidity << endl;
    for (int i = 0; i < (int)clientAccounts.size(); i++) {
        cout << "Account " << clientAccounts[i]->getId() << ": " << clientAccounts[i]->getValue() << endl;
    }
    cout << "--------------------------------" << endl;
}

void Bank::deposit(int id, double amount) {
    for (int i = 0; i < (int)clientAccounts.size(); i++) {
        double v = amount * 0.95;
        if (clientAccounts[i]->getId() == id) {
            clientAccounts[i]->deposit(v);
            _liquidity -= v;
            return;
        }
    }
    cout << "Account not found" << endl;
}

void Bank::withdraw(int id, double amount) {
    for (int i = 0; i < (int)clientAccounts.size(); i++) {
        if (clientAccounts[i]->getId() == id) {
            if (clientAccounts[i]->withdraw(amount) == 0) {
                cout << "Not enough money" << endl;
                return;
            }
            _liquidity += amount;
            return;
        }
    }
    cout << "Account not found" << endl;
}

void Bank::Loans(int id, double amount) {
    if (amount > _liquidity * 0.9) {
        cout << "Not enough liquidity" << endl;
        return;
    }
    for (int i = 0; i < (int)clientAccounts.size(); i++) {
        if (clientAccounts[i]->getId() == id) {
            clientAccounts[i]->deposit(amount);
            loans.insert(pair<int, double>(id, amount));
            _liquidity -= amount;
            return;
        }
    }
    cout << "Account not found" << endl;
}

void Bank::displayLoansList() const {
    cout << "--------------------------------" << endl;
    for (map<int, double>::const_iterator it = loans.begin(); it != loans.end(); it++) {
        cout << "Account " << it->first << ": " << it->second << endl;
    }
    cout << "--------------------------------" << endl;
}