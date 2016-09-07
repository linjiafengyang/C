#include <iostream>
using namespace std;
class  EmptyStackException {
public:
	EmptyStackException() {
		msg = "Empty Stack Exception";
	}
    string what() {
        return msg;
    }
private:
	string msg;
};
class StackOfIntegers
{
public:
  StackOfIntegers() {
    size = 0;
  }
  bool empty() {
    if (size == 0) {
        return true;
    }
    return false;
  }
  int peek() {
    if (empty() == true) {
      throw EmptyStackException();  
    }
    else {
        return a[size - 1];
    }
  }
  void push(int value) {
    a[size] = value;
    size++;
  }
  int pop() {
    if (empty() == true) {
      throw EmptyStackException();  
    }
    else {
        size--;
    }
    return size;
  }
  int getSize() {
    return size;
  }
private:
    int a[1000];
    int size;
};
void f()
{
  StackOfIntegers s;

  try
  {
    s.peek();
  }
  catch(EmptyStackException ex)
  {
    cout << ex.what() << endl;
  }
  
  try
  {
    s.pop();
  }
  catch(EmptyStackException ex)
  {
    cout << ex.what() << endl;
  }
}
int main() {
	f();
}
