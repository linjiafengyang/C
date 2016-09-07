#include <iostream>
#include <stdexcept>
using namespace std;
int calc(int a, int b) throw(logic_error)
{
  if (a<0) throw out_of_range("Out of range exeception");
  else if (b<0) throw out_of_range("Out of range exeception");
  else if (a<b) throw logic_error("Minuend smaller than subtrahend");
  return a-b;
}
void test(int a, int b) {
    try {
        cout << calc(a, b) << endl; 
    }
    catch(logic_error& ex) {
        cout << ex.what() << endl;
    }
}
void f()
{

  test(3, 1);
  test(-3,1);
  test(1,-3);
  test(1,3);
}
int main() {
	f();
}
