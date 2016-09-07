#include <iostream>
using namespace std;
template<typename T, int capacity>
class Stack
{
public:
    Stack();                 // Constructs an empty stack.
    bool empty();         // Returns true if the stack is empty.
    T peek();               // Returns the element at the top of the stack without removing it from the stack.
    void push(T value); // Stores an element into the top of the stack.
    T pop();                 // Removes the element at the top of the stack and returns it.
    int size();               // Returns the number of elements in the stack.
private:
    T* elements;          // Points to an array that stores elements in the stack.
    int num;                 // The number of the elements in the stack.
};
template<typename T, int capacity>
Stack<T, capacity>::Stack() {
	elements = new T[capacity];
	num = 0;
}
template<typename T, int capacity>
bool Stack<T, capacity>::empty() {
	if(num) {
		return false;
	}
	return true;
}
template<typename T, int capacity>
T Stack<T, capacity>::peek() {
	return elements[num - 1];
}
template<typename T, int capacity>
void Stack<T, capacity>::push(T value) {
	elements[num++] = value;
}
template<typename T, int capacity>
T Stack<T, capacity>::pop() {
	num--;
	return elements[num];
}
template<typename T, int capacity>
int Stack<T, capacity>::size() {
	return num;
}
int main(int argc, char** argv) {
	return 0;
}
