#include <iostream>
using namespace std;
void f();
class MyClass
{
    int data;
public:
    MyClass(int d);
    void printData();
    int sumIt(); 
};
MyClass::MyClass(int d) {
    data = d;
}
int MyClass::sumIt() {
    int i;
    int sum = 0;
    for(i = 1; i <= data; i++) {
        sum += i;
    }
    return sum;
}
void MyClass::printData() {
    cout << data << endl;
}
void f()
{
    MyClass mc(10);
    mc.printData();    
    cout << mc.sumIt() << endl;

    MyClass mc1(100);
    mc1.printData();
    cout << mc1.sumIt() << endl;
}
int main() {
	f();
	return 0;
}
