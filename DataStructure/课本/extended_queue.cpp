#include <iostream>
using namespace std;
enum Error_code
{
	success,
	overflow,
	underflow
};
typedef char Queue_entry;
const int maxqueue = 10;
class Queue
{
public:
	Queue();
	Error_code append(const Queue_entry &item);// 相当于stack的push
	Error_code serve();// 相当于stack的pop
	Error_code retrieve(Queue_entry &item) const;// 相当于stack的top,只不过queue是先进先出
	bool empty() const;
protected:
	int count;
	int front, rear;
	Queue_entry entry[maxqueue];
};
Queue::Queue() {
	count = 0;
	front = 0;
	rear = maxqueue - 1;
}
bool Queue::empty() const {
	return count == 0;
}
Error_code Queue::append(const Queue_entry &item) {
	if (count == maxqueue)
	{
		return overflow;
	}
	count++;
	rear = ((rear + 1) == maxqueue) ? 0 : (rear + 1);
	entry[rear] = item;
	return success;
}
Error_code Queue::serve() {
	if (count == 0)
	{
		return underflow;
	}
	count--;
	front = ((front + 1) == maxqueue) ? 0 : (front + 1);
	return success;
}
Error_code Queue::retrieve(Queue_entry &item) const {
	if (count == 0)
	{
		return underflow;
	}
	item = entry[front];
	return success;
}

class Extended_queue: public Queue
{
public:
	bool full() const;
	int size() const;
	void clear();
	Error_code serve_and_retrieve(Queue_entry &item);
};
bool Extended_queue::full() const {
	return count == maxqueue;
}
void Extended_queue::clear() {
	count = 0;
	front = 0;
	rear = maxqueue - 1;
}
int Extended_queue::size() const {
	return count;
}
Error_code Extended_queue::serve_and_retrieve(Queue_entry &item) {
	if (count == 0)
	{
		return underflow;
	}
	else {
		count--;
		item = entry[front];
		front = ((front + 1) == maxqueue) ? 0 : (front + 1);
	}
	return success;
}

int main(int argc, char const *argv[])
{
	while(cin.peek() != EOF) {
	    Extended_queue q;
	    char c;
	    int ct;
	    while((c = cin.get()) != '\n') {
	        q.append(c);
	        ct = q.size();
	    }
	   	while(q.serve_and_retrieve(c) == success) {
	        cout << c;
	    }
	    cout << ":" << ct;
	    cout << endl;
	}
	return 0;
}