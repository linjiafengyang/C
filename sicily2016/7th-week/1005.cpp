#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Complex
{
public:
    Complex(int a=0, int b=0): real(a), imag(b) {}
    friend Complex operator*(const Complex&, const Complex&);
    friend istream& operator>>(istream&, Complex&);
    friend ostream& operator<<(ostream&, const Complex&);
private:
    int real;
    int imag;
};
Complex operator*(const Complex& a, const Complex& b) {
    Complex c;
    c.real = a.real * b.real - a.imag * b.imag;
    c.imag = a.real * b.imag + a.imag * b.real;
    return c;
}
istream& operator>>(istream& i, Complex& a) {
    string b;
    i >> b;
    int j;
    a.real = 0;
    bool p = true;
    int k = 0;
    a.imag = 0;
    for (j = b.size() - 2; j >= 0; j--) {
        if (b[j] == '+') {
            k = 0;
            p = false;
            continue;
        }
        if (b[j] == '-') {
            k = 0;
            p = false;
            a.imag = -a.imag;
            continue;
        } 
        if (p) {
            a.imag += (b[j] - 48) * pow(10, k++);
        }
        else {
            a.real += (b[j] - 48) * pow(10, k++);
        }
    }
    return i; 
}
ostream& operator<<(ostream& o, const Complex& a) {
    if (a.imag >= 0) {
        o << a.real << "+" << a.imag << "i";
    }
    else {
        o << a.real << a.imag<< "i"; 
    }
    return o;
}
