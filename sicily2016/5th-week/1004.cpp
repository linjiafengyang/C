#include <iostream>
class Complex
{
public:
    Complex(int a=0, int b=0): real(a), imag(b) {}
    int& operator[] (const int c);
private:
    int real;
    int imag;
};
int& Complex::operator[] (const int c) {
    if (c == 0) {
        return real;
    }
    return imag;
}
