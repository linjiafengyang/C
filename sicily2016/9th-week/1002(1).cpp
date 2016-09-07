#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
void f();
class Complex
{
    double re; //real part of a complex number
    double im; //imaginary part of a complex number
public:
    Complex(double x = 0, double y = 0) {
        re = x;
        im = y;
    }
    Complex(const Complex& other) {
        re = other.re;
        im = other.im;
    }
    double real() const { return re; }
    double imag() const { return im; }
    Complex operator+(const Complex& other) {
        Complex t;
        t.re = re + other.re;
        t.im = im + other.im;
        return t;
    }
    friend Complex operator+(const double i, const Complex& other) {
        Complex t;
        t.re = i + other.re;
        t.im = other.im;
        return t;
    }

    Complex operator-(const Complex& other) {
        Complex t;
        t.re = re - other.re;
        t.im = im - other.im;
        return t;
    }
    friend Complex operator-(const double i, const Complex& other) {
        Complex t;
        t.re = i - other.re;
        t.im = -other.im;
        return t;
    }

    Complex operator*(const Complex& other) {
        Complex t;
        t.re = re * other.re - im * other.im;
        t.im = im * other.re + re * other.im;
        return t;
    }
    friend Complex operator*(const double i, const Complex& other) {
        Complex t;
        t.re = other.re * i;
        t.im = other.im * i;
        return t;
    }

    Complex operator/(const Complex& other) {
        Complex t;
        double x = other.re * other.re + other.im * other.im;
        t.re = (re * other.re + im * other.im) / x;
        t.im = (im * other.re - re * other.im) / x;
        return t;
    }
    friend Complex operator/(const double i, const Complex& other) {
        Complex t;
		double x = other.re * other.re + other.im * other.im;
		t.re = i * other.re / x;
		t.im = -i * other.im / x;
        return t;
    }
    void operator+=(const Complex& other) {
        re += other.re;
        im += other.im;
    }
    void operator-=(const Complex& other) {
        re -= other.re;
        im -= other.im;
    }
    void operator*=(const Complex& other) {
        double x, y;
        x = re * other.re - im * other.im;
        y = im * other.re + re * other.im;
        re = x;
        im = y;
    }
    void operator/=(const Complex& other) {
        double x, y;
        double t = other.re * other.re + other.im * other.im;
        x = (re * other.re + im * other.im) / t;
        y = (im * other.re - re * other.im) / t;
        re = x;
        im = y;
    }
    Complex operator-() {
        re = -re;
        im = -im;
        return Complex(re, im);
    }
    bool operator==(const Complex& other) {
        if(re == other.re && im == other.im) {
            return true;
        }
        return false;
    }
    friend bool operator==(const double& i, const Complex& other) {
        if(i == other.re && other.im == i) {
            return true;
        }
        return false;
    }
    bool operator!=(const Complex& other) {
        if(re != other.re || im != other.im) {
            return true;
        }
        return false;
    }
    friend bool operator!=(const double& i, const Complex& other) {
        if(i != other.re || other.im != i) {
            return true;
        }
        return false;
    }
    friend ostream& operator<<(ostream& out, const Complex& other) {
        out << "(" << other.re << "," << other.im << ")";
        return out;
    }
    friend istream& operator>>(istream& in, Complex& other) {
        char left, right, douhao;
        in >> left >> other.re >> douhao >> other.im >> right;
        return in;
    }
};                                                                 
void f()
{
  Complex a;  
  cout << a << endl; //output (0,0) 
  
  Complex b = Complex(1,2.5); 
  cout << b << endl; //output(1,2.5)
  
  Complex c(3.0);
  cout << c << endl; //output (3,0)
  
  c += a; 
  cout << c << endl; 
  
  c = c + a; 
  cout << c << endl; 
  
  c = c + 2.5; 
  cout << c << endl; 
  
  c = 2.5 + c; 
  cout << c << endl; 

  c -= a;
  cout << c << endl; 
  
  c = c - a;
  cout << c << endl; 

  c = c - 2.5;
  cout << c << endl; 
  
  c = 2.5 - c;
  cout << c << endl; 
  
  c *= b;
  cout << c << endl; 
  
  c = c * b;
  cout << c << endl; 

  c = c * 2.5;
  cout << c << endl; 
  
  c = 2.5 * c;
  cout << c << endl; 
  
  c /= b;
  cout << c << endl; 
  
  c = c / b;
  cout << c << endl; 

  c = c / 2.5;
  cout << c << endl; 
  
  c = 2.5 / c;
  cout << c << endl; 
  
  c = a+2.5+a + b*2.5*b;
  cout << c << endl;

  c = -b;
  cout << c << endl;
   
  cout << (a==a) << endl; //output 1
  cout << (a==0.0) << endl; //output 1
  cout << (0.0==a) << endl; //output 1
  cout << (a!=a) << endl; //output 0 
  cout << (a!=0.0) << endl; //output 0
  cout << (0.0!=a) << endl; //output 0  

  cin >> c; //输入格式(a,b)表示复数a + b i
  cout << c << endl;
}
int main() {
	f();
	return 0;
}
