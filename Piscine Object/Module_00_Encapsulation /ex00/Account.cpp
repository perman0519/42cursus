#include "Account.hpp"

Account::Account(int v, int id) :  _id(id), _value(v) {}
Account::~Account() {}

int Account::getId() const { return _id; }
int Account::getValue() const { return _value; }

void Account::deposit(double amount) { _value += amount; }
int Account::withdraw(double amount) {
    if (_value < amount) return 0;
    _value -= amount;
    return amount;
}