#include <iostream>
using namespace std;
class A
{
public:
    A(int a0):a(a0) {}
    void show() { cout<<"a="<<a<<endl; }
private:
    int a;
};
class B: public A
{
public:
    B(int a1, int b1): A(a1) {
    	b = b1;
	}
    void show() {
    	A::show();
    	cout << "b=" << b << endl;
	}
private:
    int b;
};
int main(int argc, char** argv) {
	B b(1, 2);
    b.show();
	return 0;
}
