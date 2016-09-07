#include <iostream>
using namespace std;
class A
{
public:
    A() {
        cout << "A constructor" << endl;
        g();//µ÷ÓÃ 
    }
    virtual void g()
    {
      fun();
    }
    virtual void fun() {
        cout << "Call class A's fun" << endl;
    }
    virtual ~A() {
        cout << "A destructor" << endl;
    }
};
class B:public A
{  
public:
    B(){
        cout << "B constructor" << endl;
    }
    ~B() {
        cout << "B destructor" << endl;
    }
};
class C:public B
{  
public:
    C(){
        cout << "C constructor" << endl;
    }
    void fun() {
        cout << "Call class C's fun" << endl;
    }
    void g()
    {
      fun();
    }
    ~C() {
        cout << "C destructor" << endl;
    }
};
int main()
{  
	A *a=new C;
	a->g();
	delete a;
	return 0;
}
