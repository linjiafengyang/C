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
	long getNumerator() {
		return numerator;
	}
	long getDenominator() {
		return denominator;
	}
	Rational add(Rational &secondRational) {
		long n = numerator * secondRational.denominator + denominator * secondRational.numerator;
		long d = denominator * secondRational.denominator;
		return Rational(n, d);
	}
	Rational subtract(Rational &secondRational) {
		long n = numerator * secondRational.denominator - denominator * secondRational.numerator;
		long d = denominator * secondRational.denominator;
		return Rational(n, d);
	}
	Rational multiply(Rational &secondRational) {
		long n = numerator * secondRational.numerator;
		long d = denominator * secondRational.denominator;
		return Rational(n, d);
	}
	Rational divide(Rational &secondRational) {
		long n = numerator * secondRational.denominator;
		long d = denominator * secondRational.numerator;
		return Rational(n, d);
	}
  /* Returns an int value -1, 0, or 1 to indicate whether this rational
     number is less than, equal to, or greater than the specified number.
  */
/*Лђеп 
	int compareTo(Rational &secondRational) {
		double a = numerator / denominator;
		double b = secondRational.numerator / secondRational.denominator;
		if(a == b) {
			return 0;
		}
		else if(a < b) {
			return -1;
		}
		else {
			return 1;
		}
	}
*/
	int compareTo(Rational &secondRational) {
		Rational temp = this -> subtract(secondRational);
		if(temp.getNumerator() < 0) {
			return -1;
		}
		else if(temp.getNumerator() == 0) {
			return 0;
		}
		else {
			return 1;
		}
	}
/*
	bool equals(Rational &secondRational) {
		double a = numerator / denominator;
		double b = secondRational.numerator / secondRational.denominator;
		if (a == b) {
			return true;
		}
		return false;
	}
*/
	bool equals(Rational &secondRational) {
		if(this -> compareTo(secondRational) == 0) {
			return true;
		}
		return false;
	}
	//Returns the numerator/denominator
	int intValue() {
		return numerator / denominator;
	}
	//Returns 1.0*numberator/denominator
	double doubleValue() {
		return 1.0 * numerator / denominator;
	}
	string toString() {
		char s[50];
		if(denominator == 1) {
			sprintf(s, "%ld", numerator);
		}
		else {
			sprintf(s, "%ld/%ld", numerator, denominator);
		}
		return string(s);
	}

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
int main() {
	Rational r1(4, 2);
	Rational r2(1, 2);
	cout << r1.toString() << "+" << r2.toString() << "="
		 << r1.add(r2).toString() << endl;
	cout << r1.toString() << "-" << r2.toString() << "="
		 << r1.subtract(r2).toString() << endl;
	cout << r1.toString() << "*" << r2.toString() << "="
		 << r1.multiply(r2).toString() << endl;
	cout << r1.toString() << "/" << r2.toString() << "="
		 << r1.divide(r2).toString() << endl;
	cout << "r2.intValue()" << "is" << r2.intValue() << endl;
	cout << "r2.doubleValue()" << "is" << r2.doubleValue() << endl;
	cout << "r1.compareTo(r2)" << "is" << r1.compareTo(r2) << endl;
	cout << "r2.compareTo(r1)" << "is" << r2.compareTo(r1) << endl;
	cout << "r1.compareTo(r1)" << "is" << r1.compareTo(r1) << endl;
	cout << "r1.equals(r1)" << "is" << r1.equals(r1) << endl;
	cout << "r1.equals(r2)" << "is" << r1.equals(r2) << endl;
	return 0;
}
