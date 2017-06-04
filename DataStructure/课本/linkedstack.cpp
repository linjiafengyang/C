#include <iostream>
using namespace std;
typedef char Node_entry;
typedef Node_entry Stack_entry;
enum Error_code
{
	success,
	overflow,
	underflow
};
struct Node
{
	Node_entry entry;
	Node *next;
	Node();
	Node(Node_entry item, Node *add_on = NULL);
};
Node::Node() {
	next = NULL;
}
Node::Node(Node_entry item, Node *add_on) {
	entry = item;
	next = add_on;
}
class Stack
{
public:
	Stack();
	bool empty() const;
	Error_code push(const Stack_entry &item);
	Error_code pop();
	Error_code top(Stack_entry &item) const;
	~Stack();
	Stack(const Stack &original);
	void operator=(const Stack &original);
protected:
	Node *top_node;
};
Stack::Stack() {
	top_node = NULL;
}
bool Stack::empty() const {
	return top_node == NULL;
}
Error_code Stack::push(const Stack_entry &item) {
	Node *new_top = new Node(item, top_node);
	if (new_top == NULL)
	{
		return overflow;
	}
	top_node = new_top;
	return success;
}
Error_code Stack::top(Stack_entry &item) const {
	if (top_node == NULL)
	{
		return underflow;
	}
	item = top_node->entry;
	return success;
}
Error_code Stack::pop() {
	Node *old_top = top_node;
	if (top_node == NULL)
	{
		return underflow;
	}
	top_node = old_top->next;
	delete old_top;
	return success;
}

Stack::Stack(const Stack &original) {
	Node *new_copy, *original_node = original.top_node;
	if (original_node == NULL)
	{
		top_node = NULL;
	}
	else {
		top_node = new_copy = new Node(original_node->entry);
		while (original_node->next != NULL) {
			original_node = original_node->next;
			new_copy->next = new Node(original_node->entry);
			new_copy = new_copy->next;
		}
	}
}
void Stack::operator=(const Stack &original) {
	Node *new_top, *new_copy, *original_node = original.top_node;
	if (original_node == NULL)
	{
		new_top = NULL;
	}
	else {
		new_copy = new_top = new Node(original_node->entry);
		while (original_node->next != NULL) {
			original_node = original_node->next;
			new_copy->next = new Node(original_node->entry);
			new_copy = new_copy->next;
		}
	}
	while (!empty()) {
		pop();
	}
	top_node = new_top;
}
Stack::~Stack() {
	while (!empty()) {
		pop();
	}
}

class Extended_stack: public Stack {
public:
	void clear();
	bool full() const;
	int size() const;
	Error_code pop_and_top(Stack_entry &item);
};
void Extended_stack::clear() {
	while(top_node != NULL) {
	    Node *temp_node = top_node;
	    top_node = top_node->next;
	    delete temp_node;
	}
}
bool Extended_stack::full() const {
	Node *test_node = new Node();
	if (test_node == NULL)
	{
		return true;
	}
	delete test_node;
	return false;
}
int Extended_stack::size() const {
	Node *new_copy = top_node;
	int count = 0;
	while (new_copy != NULL) {
		count++;
		new_copy = new_copy->next;
	}
	return count;
}
Error_code Extended_stack::pop_and_top(Stack_entry &item) {
	Node *old_top = top_node;
	if (top_node == NULL)
	{
		return underflow;
	}
	top_node = old_top->next;
	delete old_top;

	if (top_node == NULL)
	{
		return underflow;
	}
	item = top_node->entry;
	return success;
}

int main(int argc, char const *argv[])
{
	char c;
	Extended_stack data;
	c = '0';
	data.top(c);
	cout << "try to pop on empty stack, expecting garbage ie. 0:" << c << endl;

	cout << "push a, b, c" << endl;
	data.push('a');
	data.push('b');
	data.push('c');
	data.top(c);
	cout << "Top c:" << c << endl;
	data.pop();
	data.top(c);
	cout << "Top b:" << c << endl;
	data.pop();
	data.top(c);
	cout << "Top a:" << c << endl;
	data.pop();

	c = '0';
	data.top(c);
	cout << "try to pop on empty stack, expecting garbage ie. 0:" << c << endl;

	cout << "push x, y, z" << endl;
	data.push('x');
	data.push('y');
	data.push('z');
	cout << "size:" << data.size() << endl;
	cout << "full:" << data.full() << endl;
	data.pop_and_top(c);
	cout << "pop_and_top y:" << c << endl;
	data.clear();

	c = '0';
	data.top(c);
	cout << "clear empty:" << data.empty() << endl;

	c = '0';
	data.pop_and_top(c);
	cout << "try to pop_and_top on empty stack, expecting garbage ie. 0:" << c << endl;
	return 0;
}