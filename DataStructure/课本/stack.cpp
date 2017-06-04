#include <iostream>
using namespace std;
const int maxstack = 10;
enum Error_code
{
	success,
	overflow,
	underflow
};
typedef int Stack_entry;
class Stack
{
public:
	Stack();
	bool empty() const;
	Error_code pop();
	Error_code top(Stack_entry &item) const;
	Error_code push(const Stack_entry &item);
private:
	int count;
	Stack_entry entry[maxstack];
};
Stack::Stack() {
	count = 0;
}
bool Stack::empty() const {
	bool outcome = true;
	if (count > 0)
	{
		outcome = false;
	}
	return outcome;
}
Error_code Stack::push(const Stack_entry &item) {
	Error_code outcome = success;
	if (count == maxstack)
		return overflow;
	else 
		entry[count++] = item;
	return outcome;
}
Error_code Stack::pop() {
	Error_code outcome = success;
	if (count == 0)
	{
		outcome = underflow;
	}
	else {
		--count;
	}
	return outcome;
}
Error_code Stack::top(Stack_entry &item) const {
	Error_code outcome = success;
	if (count == 0)
	{
		outcome = underflow;
	}
	else {
		item = entry[count - 1];
	}
	return outcome;
}

int main(int argc, char const *argv[])
{
	int n;
	int item;
	Stack numbers;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> item;
		if (numbers.push(item) == overflow)
		{
			cout << "the stack is full." << endl;
		}
	}
	while(!numbers.empty()) {
	    numbers.top(item);
	    numbers.pop();
	    cout << item << " ";
	}
	return 0;
}