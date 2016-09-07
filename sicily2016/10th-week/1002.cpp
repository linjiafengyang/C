#include <iostream>
#include <cmath>
using namespace std;
class GeometricObject
{
public:
	GeometricObject(){
	}
  GeometricObject(string color, bool filled)
  {
    this->color = color;
    this->filled = filled;
  }
  
  string getColor()
  { return color; }
  void setColor(string color)
  { this->color = color; }
  bool isFilled()
  { return filled; }
  void setFilled(bool filled)
  { this->filled = filled;}
  string toString()
  {
    return "Geometric object color " + color +
    " filled " + ((filled) ? "true" : "false");
  }
private:
  string color;
  bool filled;
};
class Triangle: public GeometricObject {
    private:
        double side1, side2, side3;
    public:
		double getSide1() {
    		return side1;
		}
		double getSide2() {
    		return side2;
		}
		double getSide3() {
    		return side3;
		}
		Triangle() {
    		side1 = 1.0;
    		side2 = 1.0;
    		side3 = 1.0;
    		setColor("blue");
    		setFilled(true);
		}
		Triangle(double a, double b, double c) {
    		side1 = a;
    		side2 = b;
    		side3 = c;
    		setColor("blue");
    		setFilled(true);
		}
		double getArea() {
    		double p = (side1 + side2 + side3) / 2;
    		return sqrt(p * (p - side1) * (p - side2) * (p - side3));
		}
		double getPerimeter() {
    		return side1 + side2 + side3;
		}
};
