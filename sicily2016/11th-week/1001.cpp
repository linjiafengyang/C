#include <iostream>
#include <cmath>
using namespace std;
class MyPoint
{
  private:
    double x, y;
  public:
    // The no-arg constructor that contruccts a point with coordinates(0,0)
    MyPoint() {
        x = 0.0;
        y = 0.0;
    }

    MyPoint(double x1, double y1) {
         x = x1;
         y = y1;
    }
    double getX() const {
        return x;
    }
    double getY() const {
        return y;
    }

    //display the distance between two points in two-dimensional space.
    double distance(const MyPoint &point) {
        return sqrt((point.x - x) * (point.x - x) + (point.y - y) * (point.y - y));
    }
};

class ThreeDPoint : public MyPoint
{
private:
  double z;
public:
  // The no-arg constructor that contruccts a point with coordinates(0,0,0)  
  ThreeDPoint() {
    z = 0.0;
  }

  ThreeDPoint(double x1, double y1, double z1):MyPoint(x1, y1){
    z = z1;
  }
  double getZ() const {
    return z;
  }

  //display the distance between two points in Three-dimensional space.
  double distance(const ThreeDPoint &point) {
    return sqrt((this->getX() - point.getX()) * (this->getX() - point.getX()) + (point.getY() - this->getY()) * (point.getY() - this->getY()) + (point.getZ() - this->getZ()) * (point.getZ() - this->getZ()));
  }
};
int main() {
	MyPoint a;
	MyPoint b(1,1);
	cout << a.distance(b) << endl;
	ThreeDPoint c;
	ThreeDPoint d(0,1,1);
	cout << c.distance(d) << endl;
}
