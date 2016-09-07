#include <iostream>
using namespace std;
class Date
{
public:
    Date();
    Date(int y, int m, int d) { year=y; month=m; day=d; }
    int getYear() { return year; }
    int getDay() {return day;}
    int getMonth() {return month;}
    void setYear(int y) { year = y; }
private:
    int year, month, day;
};
 
class Person
{
public:
    Person(Person &a);
    Person(int id, int year, int month, int day) {
        this->id = id;
        birthDate = new Date(year, month, day);
    }
    ~Person() { delete birthDate; }
    int getId() { return id; }
    Date* getBirthDate() const{ return birthDate; }
private:
    int id;
    Date* birthDate;
};
Date::Date() {
};
Person::Person(Person &a) {
    id = a.id;
    birthDate = new Date(a.getBirthDate()->getYear(), a.getBirthDate()->getMonth(), a.getBirthDate()->getDay());
}
