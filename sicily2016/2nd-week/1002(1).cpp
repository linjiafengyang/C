// Problem#: 17657
// Submission#: 4529100
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
using namespace std;
class Fan
{
public:
  int speed;
  bool on;
  double radiu;
  string color;
  Fan();
  int getSpeed();
  void setSpeed(int a);
  bool isOn();
  void setOn(bool a);
  double getRadius();
  void setRadius(double a);
  string getColor();
  void setColor(string a);
};
Fan::Fan() {
    speed = 1;
    on = false;
    radiu = 5;
    color = "blue";
}
int Fan::getSpeed() {
    return speed;
}
void Fan::setSpeed(int a) {
    speed = a;
}
bool Fan::isOn() {
    return on;
}
void Fan::setOn(bool a) {
    on = a;
}
double Fan::getRadius() {
    return radiu;
}
void Fan::setRadius(double a) {
    radiu = a;
}
string Fan::getColor() {
    return color;
}
void Fan::setColor(string a) {
    color = a;
}                                 
