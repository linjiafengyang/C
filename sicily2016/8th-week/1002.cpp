#include <iostream>
using namespace std;
void f();
class Int
{
  int i;
public:
  int getI() { return i; }
  Int(int b) { i = b; }
  Int(double b) { i = b; }

  friend int operator+(int b, Int a) {
  	return b + a.i;
  }
  friend double operator+(double b, Int a) {
  	return b + a.i;
  }

  friend int operator-(int b, Int a) {
  	return b - a.i;
  }
  friend double operator-(double b, Int a) {
  	return b - a.i;
  }

  friend int operator/(int b, Int a) {
  	return b / a.i;
  }
  friend double operator/(double b, Int a) {
  	return b / a.i;
  }

  friend int operator*(int b, Int a) {
  	return b * a.i;
  }
  friend double operator*(double b, Int a) {
  	return b * a.i;
  }

  friend int operator%(int b, Int a) {
  	return b % a.i;
  }
  void operator+=(int b) {
  	i += b;
  }
  void operator+=(double b) {
  	i += b;
  }
  void operator-=(int b) {
  	i -= b;
  }
  void operator-=(double b) {
  	i -= b;
  }
  void operator*=(int b) {
  	i *= b;
  }
  void operator*=(double b) {
  	i *= b;
  }
  void operator/=(int b) {
  	i /= b;
  }
  void operator/=(double b) {
  	i /= b;
  }
  int operator++(int b) {
  	return i++;
  }
  int& operator++() {
  	return ++i;
  }
  int operator--(int b) {
  	return i--;
  }
  int& operator--() {
  	return --i;
  }
  friend ostream& operator<<(ostream& o, Int& b) {
  	o << b.i;
  	return o;
  }
  friend istream& operator>>(istream& in, Int& b) {
  	in >> b.i;
  	return in;
  }
  operator int() const {
  	return i;
  }
};

void f()
{
  Int a=0;
  Int b(1);
  Int c(2.5);
  Int d = 99.5;

  cout <<  a << endl;
  cout <<  b << endl;
  cout <<  c << endl;
  cout <<  d << endl;
  
  d += 1;
  d += 1.5;
  cout <<  c+d << endl;
  cout <<  1+c << endl;
  cout <<  c+1 << endl;
  cout <<  1.5+c << endl;
  cout <<  c+1.5 << endl;

  cout <<  a + b + c + d << endl;

  d -= 1;
  d -= 1.5;
  cout <<  c-d << endl;
  cout <<  1-c << endl;
  cout <<  c-1 << endl;
  cout <<  1.5-c << endl;
  cout <<  c-1.5 << endl;

  d *= 1;
  d *= 1.5;
  cout <<  c*d << endl;
  cout <<  9*c << endl;
  cout <<  c*9 << endl;
  cout <<  19.4*c << endl;
  cout <<  c*19.4 << endl;
  d /= 2;
  d /= 2.5;
  cout <<  d/c << endl;
  cout <<  2/c << endl;
  cout <<  c/2 << endl;
  cout <<  2.5/c << endl;
  cout <<  c/2.5 << endl;

  cout <<  b%c << endl;
  cout <<  5%c << endl;
  cout <<  c%2 << endl;

  cout <<  c++ << endl;
  cout <<  ++c << endl;
  cout <<  c-- << endl;
  cout <<  --c << endl;    
  cout <<  -c << endl;
  
  int c1 = c;
  cout << c1 << endl;
  c1 = c;  
  cout << c1 << endl;  

  cin >> d;
  cout <<  d << endl;
}

int main(int argc, char** argv) {
	f(); 
	return 0;
}
