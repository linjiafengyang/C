#include <iostream>
using namespace std;
class Point
{  
    int x,y;
public:
	Point() {
		x = 0;
		y = 0;
	}
    Point(int x1,int y1) {
    	x = x1;
    	y = y1;
	}
    void Move(int x1,int y1) {
    	x = x + x1;
    	y = y + y1;
	}
    int Getx() {
    	return x;
	}
    int Gety() {
    	return y;
	}
};
class Rectangle: public Point {
	private:
		int width, high;
	public:
		Rectangle() {
		}
		Rectangle(int x1, int y1, int width1, int high1): Point(x1, y1){
			width = width1;
			high = high1;
		}
		int Getlength() {
			return width;
		}
		int Getwidth() {
			return high;
		}
		int Getarea() {
			return width * high;
		}
};
int main(int argc, char** argv) {
	int x, y, length, width, xmove, ymove;
	cin>>x>>y;
	Point p(x,y);
    cin>>length>>width;
    Rectangle R(x,y,length,width);
    cin>>xmove>>ymove;
    R.Move(xmove,ymove);
    cout <<R.Getx()<<" "<<R.Gety()<<" "
    	 <<R.Getlength()<<" "<<R.Getwidth()
    	 <<" "<<R.Getarea()<<endl;


	return 0;
}
