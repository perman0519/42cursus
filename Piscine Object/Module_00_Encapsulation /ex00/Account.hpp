#pragma once

class Bank; // Bank 클래스를 전방선언

class Account {
    friend class Bank; // Bank 클래스에서 Account 클래스의 private 멤버에 접근 가능하도록 선언

private:
    int _id;
    int _value;
    void deposit(double amount);
    int withdraw(double amount);

public:
    Account(int v = 0, int id = 0);
    ~Account();

    const int getId() const;
    const int getValue() const;
};