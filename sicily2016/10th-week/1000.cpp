#include <iostream>
using namespace std;
class Point{
private:
	double x,y;
public:
	Point();
	Point(double xv,double yv);
	Point(Point& pt);
	double getx();
	double gety();
};
Point::Point() {
    x = 0;
    y = 0;
}
Point::Point(double xv, double yv) {
    x = xv;
    y = yv;
}
Point::Point(Point& pt) {
    x = pt.x;
    y = pt.y;
    
}
double Point::getx() {
    return x;
}
double Point::gety() {
    return y;
}
class Circle: public Point {
    public:
        Circle();
        Circle(double xv, double yv, double rv);
        Circle(Circle& c);
        int position(Point& pt);
    private:
        double x;
        double y;
        double r;
};
Circle::Circle() {
    x = 0;
    y = 0;
    r = 0;
}
Circle::Circle(double xv, double yv, double rv) {
    x = xv;
    y = yv;
    r = rv;
}
Circle::Circle(Circle& c) {
    x = c.x;
    y = c.y;
    r = c.r;
}
int Circle::position(Point& pt) {
    double dx = pt.getx() - x;
    double dy = pt.gety() - y;
    double diff = dx * dx + dy * dy - r * r;
    if(diff > 0) {
        return 1;
    }
    else if(diff < 0) {
        return -1;
    }
    else {
        return 0;
    }
}
class Rectangle: public Point {
    public:
        Rectangle();
        Rectangle(double xv, double yv, double wv, double hv);
        Rectangle(Rectangle& r);
        int position(Point& pt);
    private:
        double x;
        double y;
        double w;
        double h;
};
Rectangle::Rectangle() {
    x = 0;
    y = 0;
    w = 0;
    h = 0;
}
Rectangle::Rectangle(double xv, double yv, double wv, double hv) {
    x = xv;
    y = yv;
    w = wv;
    h = hv;
}
Rectangle::Rectangle(Rectangle& r) {
    x = r.x;
    y = r.y;
    w = r.w;
    h = r.h;
}
int Rectangle::position(Point& pt) {
    double dx = pt.getx() - x;
    double dy = pt.gety() - y;
    if(dx > 0 && dx < w && dy > 0 && dy < h) {
        return -1;
    }
    else if((dx == 0 || dx == w) && (dy == 0 || dy == h)) {
        return 0;
    }
    else {
        return 1;
    }
}
int main()
{
	Circle cc1(3,4,5);
	Rectangle rt1(0,0,6,8);
	Point p1(0,0);
	cout<<"point p1:";
	switch(rt1.position(p1))
	{
 		case 0:cout<<"on-rectangle"<<endl;break;
 		case -1:cout<<"inside-rectangle"<<endl;break;
 		case 1:cout<<"outside-rectangle"<<endl;break;
	}
	switch(cc1.position(p1))
	{
 		case 0:cout<<"on-circle"<<endl;break;
 		case -1:cout<<"inside-circle"<<endl;break;
 		case 1:cout<<"outside-circle"<<endl;break;
	}
	return 0;
}
