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
  Date operator+(int b);
  Date operator-(int b);
  void operator+=(int b);
  void operator-=(int b);
  bool operator==(const Date &date2) const;
  bool operator<=(const Date &date2) const;
  bool operator<(const Date&date2) const;
  bool operator!=(const Date&date2) const;
  bool operator>=(const Date&date2) const;
  bool operator>(const Date&date2) const;
  Date operator++();
  Date operator++(int b);
  Date operator--();
  Date operator--(int b);
  int& operator[](string s);
  friend ostream& operator<< (ostream&, const Date&);
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
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}
int Date::getYear() const{
    return year;
}
int Date::getMonth() const{
    return month; 
}
int Date::getDay() const{
    return day;
}
Date Date::operator+(int b) {
    Date a;
    a.day = day;
    a.year = year;
    a.month = month;
    
    /*while((a.day == 365 && !leapyear(a.year)) || (a.day > 365)) {
        if (leapyear(a.year) && a.day > 365) {
            a.day -= 366;
            a.year++;
        }
        else if (!leapyear(a.year) && a.day >= 365) {
            a.day -= 365;
            a.year++;
        }
        else {
            break;
        }
    }*/
    if (a.day + b > 0) {
        a.day += b;
        while ((a.day > 28 && a.month == 2) || (a.day > 30 && (a.month == 4 || a.month == 6 || a.month == 9 || a.month == 11)) || (a.day > 31)) {
        if (a.day > 29 && a.month == 2 && leapyear(a.year)) {
            a.month++;
            a.day -= 29;
        }
        else if (a.day > 28 && a.month == 2 && !leapyear(a.year)) {
            a.month++;
            a.day -= 28;
        }
        else if (a.day > 30 && (a.month == 4 || a.month == 6 || a.month == 9 || a.month == 11)) {
            a.day -= 30;
            a.month++;
        }
        else if (a.day > 31 && (a.month == 1 || a.month == 3 || a.month == 5 || a.month == 7 || a.month == 8 || a.month == 10)) {
            a.month++;
            a.day -= 31;
        }
        else if (a.day > 31 && a.month == 12) {
            a.month = 1;
            a.year++;
            a.day -= 31;
        }
        else {
            break;
        }
    }
    return a; 
    }
    else {
        a.day += b;
    while (a.day <= 0) {
        a.month--;
        switch (a.month) {
            case 0:
                   a.day += 31;
                   a.month = 12;
                   a.year--;
                   break;
            case 1:
                   a.day += 31;
                   break; 
            case 2:
                   if (leapyear(a.year)) {
                       a.day += 29;
                   }
                   else {
                       a.day += 28;
                   }
                   break; 
            case 3:
                   a.day += 31;
                   break;      
            case 4:
                   a.day += 30;
                   break;
            case 5:
                   a.day += 31;
                   break;
            case 6:
                   a.day += 30;
                   break;
            case 7:
                   a.day += 31;
                   break;
            case 8:
                   a.day += 31;
                   break;
            case 9:
                   a.day += 30;
                   break;
            case 10:
                   a.day += 31;
                   break;
            case 11:
                   a.day += 30;
                   break;
        }
     }
    return a;
    }
    
}
Date Date::operator-(int b) {
    Date a;
    a.day = day;
    a.year = year;
    a.month = month;
    a.day -= b;
    if (a.day <= 0) {
        while (a.day <= 0) {
        a.month--;
        switch (a.month) {
            case 0:
                   a.day += 31;
                   a.month = 12;
                   a.year--;
                   break;
            case 1:
                   a.day += 31;
                   break; 
            case 2:
                   if (leapyear(a.year)) {
                       a.day += 29;
                   }
                   else {
                       a.day += 28;
                   }
                   break; 
            case 3:
                   a.day += 31;
                   break;      
            case 4:
                   a.day += 30;
                   break;
            case 5:
                   a.day += 31;
                   break;
            case 6:
                   a.day += 30;
                   break;
            case 7:
                   a.day += 31;
                   break;
            case 8:
                   a.day += 31;
                   break;
            case 9:
                   a.day += 30;
                   break;
            case 10:
                   a.day += 31;
                   break;
            case 11:
                   a.day += 30;
                   break;
        }
     }
    return a;
    }
    else {
        while ((a.day > 28 && a.month == 2) || (a.day > 30 && (a.month == 4 || a.month == 6 || a.month == 9 || a.month == 11)) || (a.day > 31)) {
        if (a.day > 29 && a.month == 2 && leapyear(a.year)) {
            a.month++;
            a.day -= 29;
        }
        else if (a.day > 28 && a.month == 2 && !leapyear(a.year)) {
            a.month++;
            a.day -= 28;
        }
        else if (a.day > 30 && (a.month == 1 || a.month == 3 || a.month == 5 || a.month == 7 || a.month == 8 || a.month == 10)) {
            a.day -= 30;
            a.month++;
        }
        else if (a.day > 31 && a.month != 12) {
            a.month++;
            a.day -= 31;
        }
        else if (a.day > 31 && a.month == 12) {
            a.month = 1;
            a.year++;
            a.day -= 31;
        }
        else {
            break;
        }
    }
    return a; 
    }
    
}
void Date::operator+=(int b) {
    day += b;
    /*while((day == 365 && !leapyear(year)) || (day > 365)) {
        if (leapyear(year) && day > 365) {
            day -= 366;
            year++;
        }
        else if (!leapyear && day >= 365) {
            day -= 365;
            year++;
        }
        else {
            break;
        }
    }*/
    if (day > 0) {
        while ((day >= 29 && month == 2) || (day >= 31 && (month == 4 || month == 6 || month == 9 || month == 11)) || (day >= 32)) {
        if (day > 29 && month == 2 && leapyear(year)) {
            month++;
            day -= 29;
        }
        else if (day >= 29 && month == 2 && !leapyear(year)) {
            month++;
            day -= 28;
        }
        else if (day >= 31 && (month == 4 || month == 6 || month == 9 || month == 11)) {
            day -= 30;
            month++;
        }
        else if (day >= 32 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)) {
            month++;
            day -= 31;
        }
        else if (day >= 32 && month == 12) {
            month = 1;
            year++;
            day -= 31;
        }
        else {
            break;
        }
    }
    }
    else {
         while (day <= 0) {
        month--;
        switch (month) {
            case 0:
                   day += 31;
                   month = 12;
                   year--;
                   break;
            case 1:
                   day += 31;
                   break; 
            case 2:
                   if (leapyear(year)) {
                       day += 29;
                   }
                   else {
                       day += 28;
                   }
                   break; 
            case 3:
                   day += 31;
                   break;      
            case 4:
                   day += 30;
                   break;
            case 5:
                   day += 31;
                   break;
            case 6:
                   day += 30;
                   break;
            case 7:
                   day += 31;
                   break;
            case 8:
                   day += 31;
                   break;
            case 9:
                   day += 30;
                   break;
            case 10:
                   day += 31;
                   break;
            case 11:
                   day += 30;
                   break;
        }
    }
    }
}
void Date::operator-=(int b) {
    day -=  b;
    if (day <= 0) {
         while (day <= 0) {
        month--;
        switch (month) {
            case 0:
                   day += 31;
                   month = 12;
                   year--;
                   break;
            case 1:
                   day += 31;
                   break; 
            case 2:
                   if (leapyear(year)) {
                       day += 29;
                   }
                   else {
                       day += 28;
                   }
                   break; 
            case 3:
                   day += 31;
                   break;      
            case 4:
                   day += 30;
                   break;
            case 5:
                   day += 31;
                   break;
            case 6:
                   day += 30;
                   break;
            case 7:
                   day += 31;
                   break;
            case 8:
                   day += 31;
                   break;
            case 9:
                   day += 30;
                   break;
            case 10:
                   day += 31;
                   break;
            case 11:
                   day += 30;
                   break;
        }
    }
    }
    else {
        while ((day >= 29 && month == 2) || (day >= 31 && (month == 4 || month == 6 || month == 9 || month == 11)) || (day >= 32)) {
        if (day > 29 && month == 2 && leapyear(year)) {
            month++;
            day -= 29;
        }
        else if (day >= 29 && month == 2 && !leapyear(year)) {
            month++;
            day -= 28;
        }
        else if (day >= 31 && (month == 4 || month == 6 || month == 9 || month == 11)) {
            day -= 30;
            month++;
        }
        else if (day >= 32 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)) {
            month++;
            day -= 31;
        }
        else if (day >= 32 && month == 12) {
            month = 1;
            year++;
            day -= 31;
        }
        else {
            break;
        }
    }
    }
  }
bool Date::operator==(const Date &date2) const {
    if ((getYear() == date2.getYear()) && (getMonth() == date2.getMonth()) && (getDay() == date2.getDay())) {
        return true;
    }
    return false;
}
bool Date::operator<=(const Date &date2) const {
    if (getYear() < date2.getYear()) {
        return true;
    }
    if (getYear() > date2.getYear()) {
        return false;
    }
    if (getMonth() < date2.getMonth()) {
        return true;
    }
    if (getMonth() > date2.getMonth()) {
        return false;
    }
    if (getDay() <= date2.getDay()) {
        return true;
    }
    return false;
}
bool Date::operator<(const Date &date2) const {
    if (getYear() < date2.getYear()) {
        return true;
    }
    if (getYear() > date2.getYear()) {
        return false;
    }
    if (getMonth() < date2.getMonth()) {
        return true;
    }
    if (getMonth() > date2.getMonth()) {
        return false;
    }
    if (getDay() < date2.getDay()) {
        return true;
    }
    return false;
}
bool Date::operator!=(const Date &date2) const {
    if ((getYear() != date2.getYear()) || (getMonth() != date2.getMonth()) || (getDay() != date2.getDay())) {
        return true;
    }
    return false;
}
bool Date::operator>=(const Date &date2) const {
    if (getYear() > date2.getYear()) {
        return true;
    }
    if (getYear() < date2.getYear()) {
        return false;
    }
    if (getMonth() > date2.getMonth()) {
        return true;
    }
    if (getMonth() < date2.getMonth()) {
        return false;
    }
    if (getDay() >= date2.getDay()) {
        return true;
    }
    return false;
}
bool Date::operator>(const Date &date2) const {
    if (getYear() > date2.getYear()) {
        return true;
    }
    if (getYear() < date2.getYear()) {
        return false;
    }
    if (getMonth() > date2.getMonth()) {
        return true;
    }
    if (getMonth() < date2.getMonth()) {
        return false;
    }
    if (getDay() > date2.getDay()) {
        return true;
    }
    return false;
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
int& Date::operator[](string s) {
    if (s == "year")return year;
    if (s == "month")return month;
    if (s == "day")return day;
}
ostream& operator<<(ostream &out, const Date &a) {
    out << a.year << "-" << a.month  << "-" << a.day;
    return out;
}
int main() { 
  int year, month, day;
  cin >> year >> month >> day;
  Date d(year, month, day);
  Date date = d;
  cout << "date = " << date << endl;
  cout << "date+1 = " << date+1 << endl;
  cout << "date-1 = " << date-1 << endl;
  date+=366;
  cout << "date = " << date << endl;
  date-=365;
  cout << "date = " << date << endl;
  date-=-365;
  cout << "date = " << date << endl;
  date+=-366;
  cout << "date = " << date << endl;
  cout << endl;
}
