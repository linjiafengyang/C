#include <iostream>
using namespace std;
template<typename T>
class Stack
{
public:
	Stack() {
		size = 0;
	}
	bool empty() {
		if(size) {
			return false;
		}
		return true;
	}
	T peek() {
		return data[size - 1];
	}
	void push(T value) {
		data[size++] = value;
	}
	T pop() {
		size--;
		return data[size];
	}
	int getSize() {
		return size;
	}
	void printStack() {
		for(int i = size - 1; i >= 0; i--) {
			cout << data[i] << endl;
		}
	}
private:
	int size;
	T data[1000];
};

int main(int argc, char** argv) {
	Stack<int> s;
	for(int i=0;i<3;++i) s.push(i);
	s.printStack();
	s.push(3);
	s.printStack();
	return 0;
}
