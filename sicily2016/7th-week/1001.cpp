#include <iostream>
using namespace std;
class Date
{
public:
	Date(int y=0, int m=1, int d=1); 
	static bool leapyear(int year);
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	friend ostream &operator<<(ostream &out, const Date &a);
	Date operator++();
	Date operator++(int b);
	Date operator--();
	Date operator--(int b);
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
bool Date::leapyear(int year) {
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return true;
    }
    return false;
}
int Date::getYear() const{
    return year;
}
int Date::getMonth() const {
    return month;
}
int Date::getDay() const{
    return day;
}
Date Date::operator++() {
    Date a;
    day++;
    if (leapyear(year)) {
       if (day == 30 && month == 2) {
          day = 1;
          month++;
       }
       else if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)) {
           day = 1;
           month++;
       }
       else if (day == 32 && month != 12) {
           day = 1;
           month++;
       } 
       else if (day == 32 && month == 12){
           day = 1;
           month = 1;
           year++;
       }
    }
    else {
    	if (day == 29 && month == 2) {
          day = 1;
          month++;
        }
       else if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)) {
           day = 1;
           month++;
       }
       else if (day == 32 && month != 12) {
           day = 1;
           month++;
       } 
       else if (day == 32 && month == 12){
           day = 1;
           month = 1;
           year++;
       }
    }
    a.year = year;
    a.month = month;
    a.day = day;
    return a;
}
Date Date::operator++(int b) {
    Date a;
    a.year = year;
    a.month = month;
    a.day = day;
    day++;
    if (leapyear(year)) {
       if (day == 30 && month == 2) {
          day = 1;
          month++;
       }
       else if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)) {
           day = 1;
           month++;
       }
       else if (day == 32 && month != 12) {
           day = 1;
           month++;
       } 
       else if (day == 32 && month == 12){
           day = 1;
           month = 1;
           year++;
       }
    }
    else {
    	if (day == 29 && month == 2) {
          day = 1;
          month++;
        }
       else if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)) {
           day = 1;
           month++;
       }
       else if (day == 32 && month != 12) {
           day = 1;
           month++;
       } 
       else if (day == 32 && month == 12){
           day = 1;
           month = 1;
           year++;
       }
    }
    return a;
}
Date Date::operator--() {
    Date a;
    --day;
    if (day == 0) {
        month--;
        switch(month) {
            case 0:
                day = 31;
                year--;
                month = 12;
                break;
            case 1:
                day = 31;
                break;
            case 2:
                if (leapyear(year)) {
                    day = 29;
                }
                else {
                    day = 28;
                }
                break;
            case 3:
                day = 31;
                break;
            case 4:
                day = 30;
                break;
            case 5:
                day = 31;
                break;
            case 6:
                day = 30;
                break;
            case 7:
                day = 31;
                break;
            case 8:
                day = 31;
                break;
            case 9:
                day = 30;
                break;
            case 10:
                day = 31;
                break;
            case 11:
                day = 30;
                break;
        }
    }
    a.day = day;
    a.year = year;
    a.month = month;
    return a;
}
Date Date::operator--(int b) {
    Date a;
    a.day = day;
    a.year = year;
    a.month = month;
    day--;
    if (day == 0) {
        month--;
        switch(month) {
            case 0:
                day = 31;
                year--;
                month = 12;
                break;
            case 1:
                day = 31;
                break;
            case 2:
                if (leapyear(year)) {
                    day = 29;
                }
                else {
                    day = 28;
                }
                break;
            case 3:
                day = 31;
                break;
            case 4:
                day = 30;
                break;
            case 5:
                   day = 31;
                   break;
            case 6:
                day = 30;
                break;
            case 7:
                day = 31;
                break;
            case 8:
                day = 31;
                break;
            case 9:
                day = 30;
                break;
            case 10:
                day = 31;
                break;
            case 11:
                day = 30;
                break;
        }
    }
    return a;
}
