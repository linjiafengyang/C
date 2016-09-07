#include <iostream>
using namespace std;
class Complex
{
public:
    Complex(): real(0), imag(0) {}
    Complex(int a, int b): real(a), imag(b) {}
    int getReal() const { return real; }
    int getImag() const { return imag; }
    void print();
    Complex operator+(const Complex& other) {
    	Complex temp;
    	temp.real = real + other.real;
    	temp.imag = imag + other.imag;
    	return temp;
	}
	Complex operator-(const Complex& other) {
		Complex temp;
		temp.real = real - other.real;
		temp.imag = imag - other.imag;
		return temp;
	}
	Complex operator+=(const Complex& other) {
		return Complex(real += other.real, imag += other.imag);
	}
	Complex operator-=(const Complex& other) {
		return Complex(real -= other.real, imag -= other.imag);
	}
private:
    int real;
    int imag;
};
int main() {
	Complex c1(1,2);
	Complex c2(2,0);
	Complex c3(c1);
	c3 = c2 - c1;
	c1 += c2;
	c3.print();
	c1.print();
}
void Complex::print()
{	
    cout << real;
	if (imag > 0) cout << "+" << imag << "i";
	else if (imag < 0) cout << imag << "i";
	cout << "\n";
}
