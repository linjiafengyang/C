#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;
class Vector;
class Point{
public:
    Point() {
        x_ = 0;
        y_ = 0;
    }
    Point(int x, int y) : x_(x), y_(y) {
        
    }
    Point(const Point &other) {
        x_ = other.x_;
        y_ = other.y_;
    }
    friend Point operator+(const Point &point, const Vector &other);
    friend ostream& operator<<(ostream &out, const Point &point) {
        out << point.x_ << " " << point.y_;
        return out;
    }
private:
    int x_;
    int y_;
};
class Vector {
public:
    Vector():x_(0), y_(0) {
    } 
    Vector(int x, int y) : x_(x), y_(y){
        
    }
    Vector(const Vector &other) {
        x_ = other.x_;
        y_ = other.y_;
    }
    Vector operator+(const Vector &other) {
        Vector temp;
        temp.x_ = x_ + other.x_;
        temp.y_ = y_ + other.y_;
        return temp;    
    }
    friend Point operator+(const Point &point, const Vector &other);
    friend ostream& operator<<(ostream &out, const Vector &vect) {
        out << vect.x_ << " " << vect.y_;
        return out;
    }
private:
    int x_;
    int y_;
};
Point operator+(const Point &point, const Vector &other) {
        Point temp;
        temp.x_ = point.x_ + other.x_;
        temp.y_ = point.y_ + other.y_;
        return temp;
}
