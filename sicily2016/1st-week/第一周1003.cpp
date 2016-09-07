#include <iostream>
using namespace std;
class Rectangle
{
  private:
    double width, height;
  public:
    Rectangle();
    Rectangle(double m_width, double m_height);
    double getWidth();
    double getHeight();
    void setWidth(double m_width);
    void setHeight(double m_height);
    double getArea();
    double getPerimeter();  
};

Rectangle::Rectangle() {}
Rectangle::Rectangle(double m_width, double m_height) {
    width = m_height;
    height = m_height;
}
double Rectangle::getWidth() {
    return width;
}
double Rectangle::getHeight() {
    return height;
}
void Rectangle::setWidth(double m_width) {
    width = m_width;
}
void Rectangle::setHeight(double m_height) {
    height = m_height;
}
double Rectangle::getArea() {
    return width * height;
}
double Rectangle::getPerimeter() {
    return 2 * (width + height);
}
