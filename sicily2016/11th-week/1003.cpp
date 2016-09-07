#include <iostream>
#include <cmath>
using namespace std;
class B
{
public:
    B() { cout << "In B()" << endl; }
    ~B() { cout << "In ~B()" << endl; }
};
class C:public B
{
public:
    C():B(){ cout << "In C()" << endl; }
    ~C() {
        cout << "In ~C()" << endl;
    }
};
class A:public B
{
public:
    A():B(){ cout << "In A()" << endl; }
    ~A() {
        cout << "In ~A()" << endl;
    }
};
class D:public C, public A
{
public:
    D():C(), A(){ cout << "In D()" << endl; }
    ~D() {
        cout << "In ~D()" << endl;
    }
};
int main()
{
    D d;
    return 0;
}
