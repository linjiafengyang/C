#include <iostream>
using namespace std;
const double PI = 3.14;
class Shape {
public:
	virtual double GetArea() = 0;
	virtual double GetPerim() = 0;
};
class Rectangle: public Shape {
public:
	Rectangle(double a, double b) {
		x = a;
		y = b;
	}
	double GetArea() {
		return x * y;
	}
	double GetPerim() {
		return 2 * (x + y);
	}
private:
	double x;
	double y;
};
class Circle: public Shape {
public:
	Circle(double a) {
		x = a;
	}
	double GetArea() {
		return PI * x * x;
	}
	double GetPerim() {
		return 2 * PI * x;
	}
private:
	double x;
};
int main ()
{
	double n,a,b,c;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		Shape *s;
		cin>>a>>b>>c;
		s = new Rectangle(a,b);
		cout<<s->GetArea()<<" "<<s->GetPerim()<<endl;
		delete s;
		s = new Circle(c);
		cout<<s->GetArea()<<" "<<s->GetPerim()<<endl;
        delete s;
	}
	return 0;

}
