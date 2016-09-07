#include <iostream>
using namespace std;
class Cat
{
    int data;
public:
    Cat() {
        data = 0;
        cout << "Default Constructor of Cat is Running" << endl;
    }
    Cat(int a) {
        data = a;
        cout << "Constructor of Cat is Running " << a << endl;
    }
    ~Cat() {
        cout << "Destructor of Cat is Running " << data << endl;
    }
};

class Tiger : public Cat
{
    int data;
public:
	Tiger():Cat() {
		data = 0;
		cout << "Default Constructor of Tiger is Running" << endl;
	}
    Tiger(int a):Cat(a) {
        data = a;
        cout << "Constructor of Tiger is Running " << a << endl;
    }
    ~Tiger() {
         cout << "Destructor of Tiger is Running " << data << endl;
    }
};
int main()
{
    Cat bc;
    Tiger dc(6);
    Tiger dc1(18);

    return 0;
}
