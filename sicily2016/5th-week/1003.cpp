#include <iostream>
class Point
{
public:
    Point(int x1=0,int y1=0) { x=x1, y=y1; }
	friend bool operator<(const Point& obj1, const Point& obj2) {
		return obj1.x < obj2.x || (obj1.x == obj2.x && obj1.y < obj2.y);
	}
private:
    int x, y;
};
