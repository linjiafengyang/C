#include <iostream>
using namespace std;
class Account {
public:
    int id;
    double balance;
    double annuallnterestRate;
    Account();
    int getId();
    double getBalance();
    void setId(int a);
    void setBalance(double a);
    void setAnnualInterestRate(double a);
    double getMonthlyInterestRate();
    void withDraw(double a);
    void deposit(double a);
};
/*int main() {
    Account a;
}*/
Account::Account() {
}
double Account::getMonthlyInterestRate() {
    double temp = annuallnterestRate / 12;
    return temp;
}
void Account::withDraw(double a) {
    balance -= a;
}
void Account::deposit(double a) {
    balance += a;
}
int Account::getId() {
    return id;
}
double Account::getBalance() {
    return balance;
}
void Account::setId(int a) {
    id = a;
}
void Account::setBalance(double a) {
    balance = a;
}
void Account::setAnnualInterestRate(double a) {
    annuallnterestRate = a;
}
