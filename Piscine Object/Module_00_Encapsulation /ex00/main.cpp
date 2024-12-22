#include "Account.hpp"
#include "Bank.hpp"
using namespace std;

int main() {
    Bank bank;
    bank.createAccount(100);
    bank.createAccount(200);
    bank.createAccount(300);
    bank.displayAccounts();
    bank.deposit(0, 50);
    bank.withdraw(0, 100);
    bank.deleteAccount(0);
    bank.displayAccounts();

    bank.Loans(1, 500);
    bank.displayAccounts();
    bank.displayLoansList();
    return 0;
}