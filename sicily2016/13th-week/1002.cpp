#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class Land {
public:
	Land():price_(0) {
	}
	explicit Land(int price) {
		price_ = price;
	}
	virtual double CalMoney() = 0;
protected:
	int price_;
};
class Square: public Land {
public:
	Square(double len, int price) {
		len_ = len;
		price_ = price;
	}
	double CalMoney() {
		return len_ * len_ * price_;
	}
private:
	double len_;
};
class Circle: public Land {
public:
	Circle(double radius, int price) {
		radius_ = radius;
		price_ = price;
	}
	double CalMoney() {
		return acos(-1) * radius_ * radius_ * price_;//acos(-1)±íÊ¾ ¦Ð
	}
private:
	double radius_;
};
class Accountant {
public:
	Accountant(): money_(0) {
	}
	void DevelopEstate(Land* land) {
		money_ += land->CalMoney();
	}
	double CheckMoney() {
		return money_;
	}
private:
	double money_;
};
int main(int argc, const char *argv[]) {
  Accountant py;
  Circle *a = new Circle(100, 10000);
  Square *b = new Square(100, 50000);
  py.DevelopEstate(a);
  cout << setprecision(10) << py.CheckMoney() << endl;
  py.DevelopEstate(b);
  cout << setprecision(10) << py.CheckMoney() << endl;

  return 0;
}
