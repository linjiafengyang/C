#include <iostream>
#include <cmath>
class MyPoint
{
private:
    double x, y;
public:
    MyPoint();
    MyPoint(double x, double y);
    double getX();
    double getY();
    double distance(MyPoint &point);
};
MyPoint::MyPoint() {
	x = 0.0;
	y = 0.0;
}
MyPoint::MyPoint(double x1, double y1) {
	x = x1;
	y = y1;
}
double MyPoint::getX() {
	return x;
}
double MyPoint::getY() {
	return y;
}
double MyPoint::distance(MyPoint& point) {
	return sqrt((x - point.x) * (x - point.x) + (y - point.y) * (y - point.y));
}

