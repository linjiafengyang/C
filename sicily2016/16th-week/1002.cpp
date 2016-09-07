#include <iostream>
using namespace std;
class IllegalSubscriptException {
public:
};
class Date
{
public:
    Date(int y=0, int m=1, int d=1) {
        year = y;
        month = m;
        day = d;
    }
    static bool leapyear(int year) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            return true;
        }
        return false;
    }
    int getYear() const {
        return year;
    }
    int getMonth() const {
        return month;
    }
    int getDay() const {
        return day;
    }
    bool operator<(Date &d) {
        if (year < d.getYear()) {
            return true; 
        }
        if (month < d.getMonth()) {
            return true;
        }
        if (day < d.getDay()) {
            return true;
        }
        return false;
    }
    bool operator<=(Date &d) {
        if (year < d.getYear()) {
            return true; 
        }
        if (month < d.getMonth()) {
            return true;
        }
        if (day < d.getDay()) {
            return true;
        }
        if (year == d.getYear() && month == d.getMonth() && day == d.getDay()) {
            return true;
        }
        return false;
    }
    bool operator==(Date &d) {
        if (year == d.getYear() && month == d.getMonth() && day == d.getDay()) {
            return true;
        }
        return false;
    }
    bool operator!=(Date &d) {
        if (year != d.getYear() || month != d.getMonth() || day != d.getDay()) {
            return true;
        }
        return false;
    }
    bool operator>(Date &d) {
        if (year > d.getYear()) {
            return true; 
        }
        if (month > d.getMonth()) {
            return true;
        }
        if (day > d.getDay()) {
            return true;
        }
        return false;
    }
    bool operator>=(Date &d) {
        if (year > d.getYear()) {
            return true; 
        }
        if (month > d.getMonth()) {
            return true;
        }
        if (day > d.getDay()) {
            return true;
        }
        if (year == d.getYear() && month == d.getMonth() && day == d.getDay()) {
            return true;
        }
        return false;
    }
    int &operator[](const string &s) {
        if (s == (string)"year") {
            return year;
        }
        else if (s == (string)"month") {
            return month;
        } 
        else if (s == (string)"day") {
            return day;
        }
        else {
            throw IllegalSubscriptException();
        }
    }
 private:
    int day;
    int month;
    int year;   
  // add any member you need here  
};
void f()
{
  Date date1(2011,4,1);
  try
  {
    cout << date1["abc"] << endl;
  }
  catch(IllegalSubscriptException ex)
  {
    cout << "Illegal Subscript Exception" << endl;  
  }

  try
  {
      date1["abc"] = 2000;
  }
  catch(IllegalSubscriptException ex)
  {
    cout << "Illegal Subscript Exception" << endl;
  }
}
int main() {
	f();
}
