#include <iostream>
using namespace std;
class Stock
{ 
public:
    string symbol;
    string name;
    double previousClosingPrice;
    double currentPrice;
    Stock(string m_symbol, string m_name);
    string getName();
    string getSymbol();
    double getPreviousClosingPrice();
    double getCurrentPrice();
    void setPreviousClosingPrice(double m_previousClosingPrice);
    void setCurrentPrice(double m_currentPrice);
    double changePercent();
};
int main(){
	Stock a("sd", "sd");
	return 0; 
}
Stock::Stock(string m_symbol, string m_name) {
    symbol = m_symbol;
    name = m_name;
}
string Stock::getSymbol() {
    cin >> symbol;
    return symbol;
}
string Stock::getName() {
    cin >> name;
    return name;
}
double Stock::getPreviousClosingPrice() {
    cin >> previousClosingPrice;
    return previousClosingPrice;
}
double Stock::getCurrentPrice() {
    cin >> currentPrice;
    return currentPrice;
}
void Stock::setPreviousClosingPrice(double m_previousClosingPrice) {
    previousClosingPrice = m_previousClosingPrice;
}
void Stock::setCurrentPrice(double m_currentPrice) {
    currentPrice = m_currentPrice;
}
double Stock::changePercent() {
    double a = (currentPrice - previousClosingPrice) / previousClosingPrice * 100;
    return a;
}
