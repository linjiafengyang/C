#include <iostream>
using namespace std;
class Date
{
public:
  Date(int newYear, int newMonth, int newDay);
  int getYear();
  void setYear(int newYear);
private:
  int year;
  int month;
  int day;
};

class Person
{
public:
  Person(int id, int year, int month, int day);
  Person(Person & a); 
  ~Person();
  int getId();
  Date * getBirthDate();
  static int getNumberOfObjects();
private:
  int id;
  Date *birthDate; 
  static int numberOfObjects;
};
int Person::numberOfObjects = 0;
Date::Date(int newYear, int newMonth, int newDay) {
	year = newYear;
	month = newMonth;
	day = newDay;
}
int Date::getYear() {
	return year;
}
void Date::setYear(int newYear) {
	year = newYear;
}
Person::Person(int id_, int year_, int month_, int day_) {
	id = id_;
	birthDate = new Date(year_, month_, day_);
	numberOfObjects++;
}
Person::Person(Person & a) {
	id = a.getId();
	birthDate = new Date(a.getBirthDate()->getYear(), 1, 1);
	numberOfObjects++;
}
Person::~Person() {
	numberOfObjects--;
}
int Person::getId() {
	return id;
}
Date * Person::getBirthDate() {
	return birthDate;
}
int Person::getNumberOfObjects() {
	return numberOfObjects;
}
