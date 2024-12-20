#include "Account.hpp"

Account::Account(int v, int id) : _value(v), _id(id) {}
Account::~Account() {}

const int Account::getId() const { return _id; }
const int Account::getValue() const { return _value; }

void Account::deposit(double amount) { _value += amount; }
int Account::withdraw(double amount) {
    if (_value < amount) return 0;
    _value -= amount;
    return amount;
}