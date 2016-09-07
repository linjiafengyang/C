#include <iostream>
#include <string>
using namespace std;
class Fan {
public:
	Fan();
	int getSpeed();
	void setSpeed(int a);
	bool isOn();
	void setOn(bool a);
	double getRadius();
	void setRadius(double a);
	string getColor();
	void setColor(string a);
private:
	int speed;
	double radius;
	string color;
	bool on;
};
Fan::Fan() {
	speed = 1;
	on = false;
	radius = 5.0;
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
	return radius;
}
void Fan::setRadius(double a) {
	radius = a;
}
string Fan::getColor() {
	return color;
}
void Fan::setColor(string a) {
	color = a;
}
