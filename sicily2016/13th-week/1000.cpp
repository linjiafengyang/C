#include <iostream>
using namespace std;
class Number {
public:
	Number(int a) {
		b = a;
	}
	Number& add(int a) {
		b += a;
		return *this; 
	}
	Number& sub(int a) {
		b -= a;
		return *this; 
	}
	void print() {
		cout << b << endl; 
	}
private:
	int b;
};
int main(int argc, char** argv) {
	Number op(1);
	op.add(2).sub(3).add(4);
	op.print();
	return 0;
}
