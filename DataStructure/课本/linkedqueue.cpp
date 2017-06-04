#include <iostream>
using namespace std;
typedef char Node_entry;
typedef Node_entry Queue_entry;
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
class Queue
{
public:
	Queue();
	bool empty() const;
	Error_code append(const Queue_entry &item);// push
	Error_code serve();// pop
	Error_code retrieve(Queue_entry &item) const;// top
	~Queue();
	Queue(const Queue &original);
	void operator=(const Queue &original);
protected:
	Node *front, *rear;
};
Queue::Queue() {
	front = rear = NULL;
}
bool Queue::empty() const {
	return front == NULL;
}
Error_code Queue::append(const Queue_entry &item) {
	Node *new_rear = new Node(item);
	if (new_rear == NULL)
	{
		return underflow;
	}
	if (rear == NULL)
	{
		front = rear = new_rear;
	}
	else {
		rear->next = new_rear;
		rear = new_rear;
	}
	return success;
}
Error_code Queue::serve() {
	if (front == NULL)
	{
		return underflow;
	}
	Node *old_front = front;
	front = old_front->next;
	if (front == NULL)
	{
		rear = NULL;
	}
	delete old_front;
	return success;
}
Error_code Queue::retrieve(Queue_entry &item) const {
	if (front == NULL)
	{
		return underflow;
	}
	item = front->entry;
	return success;
}
Queue::~Queue() {
	while (!empty()) {
		serve();
	}
}
Queue::Queue(const Queue &original) {
	Node *copy_node = original.front;
	front = rear = NULL;
	while (copy_node != NULL) {
		append(copy_node->entry);
		copy_node = copy_node->next;
	}
}
void Queue::operator=(const Queue &original) {
	while (!empty()) {
		serve();
	}
	Node *copy_node = original.front;
	while (copy_node != NULL) {
		append(copy_node->entry);
		copy_node = copy_node->next;
	}
}

class Extended_queue: public Queue {
public:
	bool full() const;
	int size() const;
	void clear();
	Error_code serve_and_retrieve(Queue_entry &item);
};
bool Extended_queue::full() const {
	return false;
}
int Extended_queue::size() const {
	Node *window = front;
	int count = 0;
	while (window != NULL) {
		window = window->next;
		count++;
	}
	return count;
}
void Extended_queue::clear() {
	while (!empty()) {
		serve();
	}
}
Error_code Extended_queue::serve_and_retrieve(Queue_entry &item) {
	if (front == NULL)
	{
		return underflow;
	}
	Node *old_front = front;
	front = old_front->next;
	item = old_front->entry;
	
	if (front == NULL)
	{
		rear = NULL;
	}
	delete old_front;
	return success;
}

void introduction();
void help();
char get_command();
int do_command(char, Extended_queue &);
int main(int argc, char const *argv[])
{
	Extended_queue test_queue;
	introduction();
	while (do_command(get_command(), test_queue));
	return 0;
}
void introduction() {
   cout << "\n\t\tExtended Queue Testing Program\n\n"
      << "The program demonstrates an extended queue of "
      << "single character keys. \nAdditions occur at "
      << "the end of the queue, while deletions can only "
      << "be\ndone at the front. The queue can hold a "
      << "any number of characters.\n\n"
      << "Valid commands are to be entered at each prompt.\n"
      << "Both upper and lower case letters can be used.\n"
      << "At the command prompt press H for help.\n\n";
}
void help() {
   char c;
   cout << "\nThis program allows one command to be entered on each line.\n"
      << "For example, if the command S is entered at the command line then\n"
      << "the program will serve the front of the queue."
      << "\nValid commands are:\n"
      << "\tS - Serve the front of the extended queue\n"
      << "\t# - The current size of the extended queue\n"
      << "\tA - Append the next input character to the extended queue\n"
      << "\tC - Clear the extended queue (same as delete)\n"
      << "\tH - This help screen\n"
      << "\tQ - Quit\n"
      << "\tP - Print the extended queue\n"
      << "\tR - Retrieve and print the front entry of the extended queue\n"
      << "Press <Enter> to continue.";
   do {
      cin.get(c);
   } while (c != '\n');
}
char get_command() {
	char c, d;
	cout << "select command and press <enter>:";
	while(1) {
		do {
			cin.get(c);
		} while (c == '\n');
		do {
			cin.get(d);
		} while (d != '\n');
		c = tolower(c);
		if (c == 's' || c == '#' || c == 'a' || c == 'c'
			 || c == 'h' || c == 'q' || c == 'p' || c == 'r')
		{
			return (c);
		}
		cout << "please enter a valid command or H for help:";
		cout << "\n\t[S]erve  entry\t[P]rint queue\t[#] size of queue\n"
         << "\t[C]lear queue\t[R]irst entry\t[A]ppend entry\n"
         << "\t[H]elp\t[Q]uit.\n";
	}
}
int do_command(char c, Extended_queue &test_queue) {
	Queue_entry x;
	switch(c) {
		case 'r':
			if (test_queue.retrieve(x) == underflow)
			{
				cout << "queue is empty." << endl;
			}
			else {
				cout << "the first entry is:" << x << endl;
			}
			break;
		case 's':
			if (test_queue.empty())
			{
				cout << "queue is empty." << endl;
			}
			else {
				test_queue.serve();
			}
			break;
		case 'a':
			if (test_queue.full())
			{
			 	cout << "queue is full." << endl;
			}
			else {
			 	cout << "enter a new key to insert:";
			 	cin.get(x);
			 	test_queue.append(x);
			}
			break;
		case 'c':
			test_queue.clear();
			cout << "queue is cleared." << endl;
			break;
		case '#':
			cout << "the size of the queue is " << test_queue.size() << endl;
			break;
		case 'h':
			help();
			break;
		case 'q':
			cout << "quit demonstration." << endl;
			return (0);
		case 'p':
			int sz = test_queue.size();
			if (sz == 0)
			{
				cout << "queue is empty." << endl;
			}
			else {
				cout << "the queue contains:" << endl;
				for (int i = 0; i < sz; ++i)
				{
					test_queue.retrieve(x);
					test_queue.append(x);
					cout << " " << x;
					test_queue.serve();
				}
				cout << endl;
			}
			break;
	}
	return (1);
}