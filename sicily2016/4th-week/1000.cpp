#include <iostream>
class Time
 {
   public:
     Time();
     Time(int totalSeconds);
     int getHour();
     int getMinute();
     int getSecond();
   private:
       int hour;
       int minute;
       int second;
 };
Time::Time(){;}
Time::Time(int totalSeconds){
    totalSeconds = hour * 3600 + minute * 60 + second;
}
int Time::getHour(){
    return hour;
}
int Time::getMinute(){
    return minute;
}
int Time::getSecond(){
    return second;
}
