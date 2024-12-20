#include "Bank.hpp"
#include <iostream>
using namespace std;

int Bank::_accountIndex = 0;

Bank::Bank(int liquidity) : _liquidity(liquidity) {}
Bank::~Bank() {
    for (auto account : clientAccounts) {
        delete account;
    }
}

void Bank::createAccount(int value) {
    clientAccounts.push_back(new Account(value, _accountIndex++));
}

void Bank::deleteAccount(int id) {
    for (auto it = clientAccounts.begin(); it != clientAccounts.end(); it++) {
        if ((*it)->getId() == id) {
            delete *it;
            clientAccounts.erase(it);
            return;
        }
    }
}

void Bank::displayAccounts() const {
    for (auto account : clientAccounts) {
        cout << "Account " << account->getId() << ": " << account->getValue() << endl;
    }
}

void Bank::displayTotal() const {
    int total = 0;
    for (auto account : clientAccounts) {
        total += account->getValue();
    }
    cout << "Total: " << total << endl;
}

void Bank::displayTotal(int id) const {
    for (auto account : clientAccounts) {
        if (account->getId() == id) {
            cout << "Account " << account->getId() << ": " << account->getValue() << endl;
            return;
        }
    }
    cout << "Account not found" << endl;
}

void Bank::deposit(int id, double amount) {
    for (auto account : clientAccounts) {
        if (account->getId() == id) {
            account->deposit(amount);
            _liquidity -= amount;
            return;
        }
    }
    cout << "Account not found" << endl;
}

void Bank::withdraw(int id, double amount) {
    for (auto account : clientAccounts) {
        if (account->getId() == id) {
            if (account->withdraw(amount) == 0) {
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
    for (auto account : clientAccounts) {
        if (account->getId() == id) {
            account->deposit(amount);
            _liquidity -= amount;
            return;
        }
    }
    cout << "Account not found" << endl;
}