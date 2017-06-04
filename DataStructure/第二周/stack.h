#include <iostream>

using namespace std;

const int maxstack = 10;
typedef char Stack_entry;
enum Error_code { success, overflow, underflow };

class Stack {
	public:
		Stack();
		bool empty() const;
		Error_code pop();
		Error_code top(Stack_entry& item) const;
		Error_code push(const Stack_entry &item);
	private:
		int count;
		Stack_entry entry[maxstack];
};

Stack::Stack() {
	count = 0;
}
bool Stack::empty() const {
	return count == 0;
}

Error_code Stack::pop() {
	Error_code outcome = success;
	if (count == 0) {
		outcome = underflow;
	}
	else {
		--count;
	}
	return outcome;
}

Error_code Stack::top(Stack_entry& item) const {
	Error_code outcome = success;
	if (count == 0) {
		outcome = underflow;
	}
	else {
		item = entry[count - 1];
	}
	return outcome;
}

Error_code Stack::push(const Stack_entry& item) {
	Error_code outcome = success;
	if (count >= maxstack) {
		outcome = overflow;
	}
	else {
		entry[count++] = item;
	}
	return outcome;
}
/*
int main(int argc, char** argv) {
	char item[10];
	Stack st;
	for (int i = 0; i < 10; i++) {
		cin >> item[i];
		cout << st.push(item[i]) << endl;
	}
	for (int j = 0; j < 10; j++) {
		cout << st.top(item[j]) << endl;
	}
	return 0;
}
*/