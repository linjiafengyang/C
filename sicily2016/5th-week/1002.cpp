#include <iostream>
using namespace std;
class Point {
    int x, y;
public:
    Point() { x = 0; y = 0; }
    Point(int a,int b) { x = a; y = b; }
    ~Point() {
         cout << "point(" << GetX() << "," << GetY() << ") has been deleted!" << endl;  
    }
    int GetX() { return x; }
    int GetY() { return y; }
};
int main() {
	Point *p = new Point(2, 3);
	p->~Point();//也可以用delete P； 
}
