#include <iostream>
using namespace std;
const int max_list = 7;
typedef int Index;
enum Error_code { success, fail, range_error, underflow, overflow, fatal,
                  not_present, duplicate_error, entry_inserted, entry_found,
                  internal_error };
template <class List_entry>
class Node {
public:
	List_entry entry;
	Index next;
};
template <class List_entry>
class List {
public:
	List();
	int size() const;
	bool full() const;
	bool empty() const;
	void clear();
	void traverse(void (*visit)(List_entry &));
	Error_code retrieve(int position, List_entry &x) const;
	Error_code replace(int position, const List_entry &x);
	Error_code remove(int position, List_entry &x);
	Error_code insert(int position, const List_entry &x);
protected:
	Node<List_entry> workspace[max_list];
	Index available, last_used, head;
	int count;
	Index new_node();
	void delete_node(Index n);
	int current_position(Index n) const;
	Index set_position(int position) const;
};
template <class List_entry>
List<List_entry>::List() {
	count = 0;
	head = -1;
	available = -1;
	last_used = -1;
}
template <class List_entry>
void List<List_entry>::clear() {
	Index p, q;
	for (p = head; p != -1; p = q) {
		q = workspace[p].next;
		delete_node(p);
	}
	count = 0;
	head = -1;
}
template <class List_entry>
int List<List_entry>::size() const {
	return count;
}
template <class List_entry>
bool List<List_entry>::empty() const {
	return count <= 0;
}
template <class List_entry>
bool List<List_entry>::full() const {
	return count >= max_list;
}
template <class List_entry>
void List<List_entry>::traverse(void (*visit)(List_entry &)) {
	for (Index n = head; n != -1; n = workspace[n].next) {
		(*visit)(workspace[n].entry);
	}
}
template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x) {
	Index new_index, previous, following;
	if (position < 0 || position > count)
	{
		return range_error;
	}
	if (position > 0)
	{
		previous = set_position(position - 1);
		following = workspace[previous].next;
	}
	else {
		following = head;
	}
	if ((new_index = new_node()) == -1)
	{
		return overflow;
	}
	workspace[new_index].entry = x;
	workspace[new_index].next = following;
	if (position == 0)
	{
		head = new_index;
	}
	else {
		workspace[previous].next = new_index;
	}
	count++;
	return success;
}
template <class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x) const {
	Index current;
	if (position < 0 || position >= count)
	{
		return range_error;
	}
	current = set_position(position);
	x = workspace[current].entry;
	return success;
}
template <class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &x) {
	Index current;
	if (position < 0 || position >= count)
	{
		return range_error;
	}
	current = set_position(position);
	workspace[current].entry = x;
	return success;
}
template <class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x) {
	Index prior, current;
	if (count == 0)
	{
		return underflow;
	}
	if (position < 0 || position >= count)
	{
		return range_error;
	}
	if (position > 0)
	{
		prior = set_position(position - 1);
		current = workspace[prior].next;
		workspace[prior].next = workspace[current].next;
	}
	else {
		current = head;
		head = workspace[head].next;
	}
	x = workspace[current].entry;
	delete_node(current);
	count--;
	return success;
}
template <class List_entry>
Index List<List_entry>::new_node() {
	Index new_index;
	if (available != -1)
	{
		new_index = available;
		available = workspace[available].next;
	}
	else if (last_used < max_list - 1)
	{
		new_index = ++last_used;
	}
	else {
		return -1;
	}
	workspace[new_index].next = -1;
	return new_index;
}
template <class List_entry>
int List<List_entry>::current_position(Index n) const {
	int i = 0;
	for (Index m = head; m != -1; m = workspace[m].next, i++) {
		if (m == n)
		{
			return i;
		}
	}
	return -1;
}
template <class List_entry>
Index List<List_entry>::set_position(int position) const {
	Index n = head;
	for (int i = 0; i < position; i++, n = workspace[n].next);
	return n;
}
template <class List_entry>
void List<List_entry>::delete_node(Index old_index) {
	Index previous;
	if (old_index == head)
	{
		head = workspace[old_index].next;
	}
	else {
		previous = set_position(current_position(old_index) - 1);
		workspace[previous].next = workspace[old_index].next;
	}
	workspace[old_index].next = available;
	available = old_index;
}


void write_entry(char &c) {
	cout << c;
}
int main(int argc, char const *argv[])
{
	char x;
	List<char> c_list;
	cout << "list is empty, it has " << c_list.size() << " items." << endl;
	cout << "enter characters and the program adds them to the list." << endl;
	cout << "use enter key to terminate the input." << endl;
	cout << "when listsize() is 3, the element will be inserted at the front of the list." << endl;
	cout << "the others will appear at the back." << endl;
	while (!c_list.full() && (x = cin.get()) != '\n') {
		if (c_list.size() == 3)
		{
			c_list.insert(0, x);
		}
		else {
			c_list.insert(c_list.size(), x);
		}
	}
	cout << "the list has " << c_list.size() << " items" << endl;
	cout << "the function c_list.full(), got " << c_list.full();
	if (c_list.full())
	{
		cout << " because the list is full." << endl;
	}
	else {
		cout << " because the list is not full." << endl;
	}
	cout << "c_list.empty(), expecting 0, got " << c_list.empty() << endl;
	cout << "c_list.traverse(write_entry) output: ";
	c_list.traverse(write_entry);
	cout << endl;
	c_list.clear();
	cout << "cleared the list, printing its contents:" << endl;
	c_list.traverse(write_entry);
	cout << endl;
	cout << "list is empty, it has " << c_list.size() << " items." << endl;
	cout << "enter characters and the program adds them to the list." << endl;
	cout << "use enter key to terminate the input." << endl;
	cout << "when listsize() is 3, the element will be inserted at the front of the list." << endl;
	cout << "the others will appear at the back." << endl;
	while (!c_list.full() && (x = cin.get()) != '\n') {
		if (c_list.size() == 3)
		{
			c_list.insert(0, x);
		}
		else {
			c_list.insert(c_list.size(), x);
		}
	}
	c_list.traverse(write_entry);
	cout << endl;
	return 0;
}