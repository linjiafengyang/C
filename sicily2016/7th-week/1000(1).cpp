#include <iostream>
void f();
using namespace std;
class Date
{
public:
	Date(int y=0, int m=1, int d=1);  
	static bool leapyear(int year);
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	bool operator<(const Date& obj2) {
		if(year < obj2.year || month < obj2.month || day < obj2.day) {
			return true;
		}
		return false;
	}
	bool operator<=(const Date& obj2) {
    	if(year <= obj2.year || month <= obj2.month || day <= obj2.day) {//用成&&也可以通过 
			return true;
    	}
    	return false;
	}
	bool operator==(const Date& obj) {
    	if(year == obj.year && month == obj.month && day == obj.day) {
			return true;
    	}
    	return false;
	}
	bool operator!=(const Date& obj) {
    	if(year != obj.year || month != obj.month || day != obj.day) {
			return true;
    	}
    	return false;
	}
	bool operator>(const Date& obj2) {
    	if(year > obj2.year || month > obj2.month || day > obj2.day) {//用成&&也可以通过 
			return true;
		}
    	return false;
	}
  	bool operator>=(const Date& obj2) {
    	if(year >= obj2.year && month >= obj2.month && day >= obj2.day) {
			return true;
		}
		return false;
	}
private:
    int year;
    int month;
    int day;  
};
Date::Date(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
}
int Date::getYear() const {
	return year;
}
int Date::getMonth() const {
	return month;
}
int Date::getDay() const {
	return day;
}
bool Date:: leapyear(int year) {
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		return true;
    }
	return false;
}
int main() {
	f();
}
void f()
{
	Date date1, date2(2003,1,1);
	Date date3 = Date(2007,2,28);
	date3 = date1;

	cout << "year 1996 is leap year? " << Date::leapyear(1996) << endl;
	cout << "year 1200 is leap year? " << Date::leapyear(1200) << endl;
	cout << "year 1300 is leap year? " << Date::leapyear(1300) << endl;
	cout << "year 1999 is leap year? " << Date::leapyear(1999) << endl;

	cout <<  "(date1==date3)? " << (date1==date3) << endl;
	cout <<  "(date1!=date3)? " << (date1!=date3) << endl;
	cout <<  "(date1==date2)? " << (date1==date2) << endl;
	cout <<  "(date1!=date2)? " << (date1!=date2) << endl;

	cout <<  "(date1<date1)? " << (date1<date1) << endl;
	cout <<  "(date1<=date1)? " << (date1<=date1) << endl;
	cout <<  "(date1<date2)? " << (date1<date2) << endl;
	cout <<  "(date1<=date2)? " << (date1<=date2) << endl;
  	
	cout <<  "(date1>date1)? " << (date1>date1) << endl;
	cout <<  "(date1>=date1)? " << (date1>=date1) << endl;
	cout <<  "(date1>date2)? " << (date1>date2) << endl;
	cout <<  "(date1>=date2)? " << (date1>=date2) << endl;
}
