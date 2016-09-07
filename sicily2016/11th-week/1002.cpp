#include <iostream>
using namespace std;
class A
{
public:
    A(int a0):a(a0) {}
    void showA() { cout<<a<<endl; }
protected:
    int a;
}; 
 
class C
{
public:
    C(int c0):c(c0) {}
    void showC() { cout<<c<<endl; }
protected:
    int c;
};

class B:public A, public C {
    public:
        B():A(11), C(22) {
        }
        B(int x):A(x), C(22){
        }
        B(int x, int y):A(x), C(y){
        }
        void showB() {
            A::showA();
            B::showB();
        }
};

int main(int argc, char** argv) {
	return 0;
}
