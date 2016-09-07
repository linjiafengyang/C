#include <iostream>
using namespace std;
void f();
class Int
{
    int data;
    static int i;
public:
    Int() {
        cout << i << " objects of Int has been constructed." << endl;
        i++;
    }
    ~Int() {
        i--;
    }
    Int(int n) {    
        cout << i << " objects of Int has been constructed." << endl;
        i++;
    }
    static int isodd(int n) {
        if(n % 2 != 0) {
            return 1;
        }
        return 0;
    }
};
int Int::i = 1;
void f()
{
    int i1=1, i2=2;
    cout << "num " << i1 << " is odd? " << Int::isodd(1) << endl;    
    cout << "num " << i2 << " is odd? " << Int::isodd(2) << endl;    
    Int ii1; 
    { Int ii1(i1); }
    Int ii2(i2);
}
int main() {
	f();
	return 0;
}
