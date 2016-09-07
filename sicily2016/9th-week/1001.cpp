#include <iostream>
#include <stdio.h>
using namespace std;
class Rational
{
public:
	Rational() {
		numerator = 0;
		denominator = 1;
	}
	Rational(long numerator1, long denominator1) {
		long factor = gcd(numerator1, denominator1);
		numerator = numerator1 / factor;
		denominator = denominator1 / factor;
	}
	string toString() {
		char s[50];
		if(denominator == 1) {
			sprintf(s, "%ld", numerator);
		}
		else {
			sprintf(s, "%ld/%ld", numerator, denominator);
		}
		return s;
	}

  // Define function operators for relational operators
	bool operator<(const Rational &secondRational) const {
		double a = numerator / denominator;
		double b = secondRational.numerator / secondRational.denominator;
		if(a < b) {
			return true;
		}
		return false;
	}
	bool operator>(const Rational &secondRational) const {
		double a = numerator / denominator;
		double b = secondRational.numerator / secondRational.denominator;
		if(a > b) {
			return true;
		}
		return false;
	}
	bool operator<=(const Rational &secondRational) const {
		double a = numerator / denominator;
		double b = secondRational.numerator / secondRational.denominator;
		if(a <= b) {
			return true;
		}
		return false;
	}
	bool operator>=(const Rational &secondRational) const {
		double a = numerator / denominator;
		double b = secondRational.numerator / secondRational.denominator;
		if(a >= b) {
			return true;
		}
		return false;
	}
	bool operator!=(const Rational &secondRational) const {
		double a = numerator / denominator;
		double b = secondRational.numerator / secondRational.denominator;
		if(a != b) {
			return true;
		}
		return false;
	}
	bool operator==(const Rational &secondRational) const {
		double a = numerator / denominator;
		double b = secondRational.numerator / secondRational.denominator;
		if(a == b) {
			return true;
		}
		return false;
	}

  // Define function operators for arithmetic operators
	Rational operator+(const Rational &secondRational) const {
		long n = numerator * secondRational.denominator + denominator * secondRational.numerator;
		long d = denominator * secondRational.denominator;
		return Rational(n, d);
	}
	Rational operator-(const Rational &secondRational) const {
		long n = numerator * secondRational.denominator - denominator * secondRational.numerator;
		long d = denominator * secondRational.denominator;
		return Rational(n, d);
	}
	Rational operator*(const Rational &secondRational) const {
		long n = numerator * secondRational.numerator;
		long d = denominator * secondRational.denominator;
		return Rational(n, d);
	}
	Rational operator/(const Rational &secondRational) const {
		long n = numerator * secondRational.denominator;
		long d = denominator * secondRational.numerator;
		return Rational(n, d);
	}

  // Define function operators for shorthand operators
	Rational operator+=(const Rational &secondRational) {
		numerator = numerator * secondRational.denominator + denominator * secondRational.numerator;
		denominator = denominator * secondRational.denominator;
		long factor = gcd(numerator, denominator);
		numerator /= factor;
		denominator /= factor;
		return *this;
	}
	Rational operator-=(const Rational &secondRational) {
		numerator = numerator * secondRational.denominator - denominator * secondRational.numerator;
		denominator = denominator * secondRational.denominator;
		long factor = gcd(numerator, denominator);
		numerator /= factor;
		denominator /= factor;
		return *this;
	}
	Rational operator*=(const Rational &secondRational) {
		numerator = numerator * secondRational.numerator;
		denominator = denominator * secondRational.denominator;
		long factor = gcd(numerator, denominator);
		numerator /= factor;
		denominator /= factor;		
		return *this;
	}
	Rational operator/=(const Rational &secondRational) {
		numerator = numerator * secondRational.denominator;
		denominator = denominator * secondRational.numerator;
		long factor = gcd(numerator, denominator);
		numerator /= factor;
		denominator /= factor;	
		return *this;
	}

  // Define function operator []
	long& operator[](const int &index) {
		if(index == 0) {
			return numerator;
		}
		else {
			return denominator;
		}
	}

  // Define function operators for prefix ++ and --
	Rational operator++() {
		numerator += denominator;
		return *this;
	}
	Rational operator--() {
		numerator -= denominator;
		return *this;
	}

  // Define function operators for postfix ++ and --
	Rational operator++(int dummy) {
		Rational temp(numerator, denominator);
		numerator += denominator;
		return temp;
	}
	Rational operator--(int dummy) {
		Rational temp(numerator, denominator);
		numerator -= denominator;
		return temp;
	}

  // Define function operators for unary + and -
	Rational operator+() {
		if(numerator / denominator < 0) {
			numerator = -numerator;
			denominator = denominator;
		}
		return *this;
	}
	Rational operator-() {
		numerator = -numerator;
		return *this;
	}

  // Define the output and input operator
	friend ostream &operator<<(ostream &stream, Rational &rational) {
		stream << rational.toString();
		return stream;
	}
	friend istream &operator>>(istream &stream, Rational &rational) {
		stream >> rational.numerator >> rational.denominator;
	}

  // Define function operator for conversion
	operator double() {
		numerator = (double)numerator;
		denominator = (double)denominator;
		return 1.0 * numerator / denominator;
	}
  
  // Add any member needed here

private:
	long numerator;
	long denominator;
	static long gcd(long n, long d) {
		long gcd = 1;
		for(int k = 1; k <= n && k <= d; k++) {
			if(n % k == 0 && d % k == 0) {
				gcd = k;
			}
		}
		return gcd;
	}
};
