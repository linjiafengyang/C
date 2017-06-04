#include <iostream>
using namespace std;
enum Error_code { success, fail, range_error, underflow, overflow, fatal,
                  not_present, duplicate_error, entry_inserted, entry_found,
                  internal_error };
template <class Node_entry>
struct Node {
	Node_entry entry;
	Node<Node_entry> *next;
	Node();
	Node(Node_entry, Node<Node_entry> *link = NULL);
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
	~List();
	List(const List<List_entry> &copy);
	void operator=(const List<List_entry> &copy);
protected:
	int count;
	Node<List_entry> *head;
	Node<List_entry> *set_position(int position) const;
};

template <class List_entry>
Node<List_entry>::Node() {
	next = NULL;
}
template <class List_entry>
Node<List_entry>::Node(List_entry data, Node<List_entry> *link) {
	entry = data;
	next = link;
}

template <class List_entry>
List<List_entry>::List() {
	count = 0;
	head = NULL;
}
template <class List_entry>
void List<List_entry>::clear() {
	Node<List_entry> *p, *q;
	for (p = head; p; p = q) {
		q = p->next;
		delete p;
	}
	count = 0;
	head = NULL;
}
template <class List_entry>
int List<List_entry>::size() const {
	return count;
}
template <class List_entry>
bool List<List_entry>::empty() const {
	return count == 0;
}
template <class List_entry>
bool List<List_entry>::full() const {
	return false;
}
template <class List_entry>
void List<List_entry>::traverse(void (*visit)(List_entry &)) {
	Node<List_entry> *q;
	for (q = head; q; q = q->next)
		(*visit)(q->entry);
}
template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x) {
	if (position < 0 || position > count)
	{
		return range_error;
	}

	Node<List_entry> *new_node, *previous, *following;
	if (position > 0)
	{
		previous = set_position(position - 1);
		following = previous->next;
	}
	else {
		following = head;
	}

	new_node = new Node<List_entry>(x, following);
	if (new_node == NULL)
	{
		return overflow;
	}

	if (position == 0)
	{
		head = new_node;
	}
	else {
		previous->next = new_node;
	}
	count++;
	return success;
}
template <class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x) const {
	Node<List_entry> *current;
	if (position < 0 || position >= count)
	{
		return range_error;
	}
	current = set_position(position);
	x = current->entry;
	return success;
}
template <class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &x) {
	Node<List_entry> *current;
	if (position < 0 || position >= count)
	{
		return range_error;
	}
	current = set_position(position);
	current->entry = x;
	return success;
}
template <class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x) {
	Node<List_entry> *prior, *current;
	if (count == 0)
	{
		return fail;
	}
	if (position < 0 || position >= count)
	{
		return range_error;
	}

	if (position > 0)
	{
		prior = set_position(position - 1);
		current = prior->next;
		prior->next = current->next;
	}
	else {
		current = head;
		head = head->next;
	}
	x = current->entry;
	delete current;
	count--;
	return success;
}
template <class List_entry>
Node<List_entry> *List<List_entry>::set_position(int position) const {
	Node<List_entry> *q = head;
	for (int i = 0; i < position; ++i)
	{
		q = q->next;
	}
	return q;
}
template <class List_entry>
List<List_entry>::~List() {
	clear();
}
template <class List_entry>
List<List_entry>::List(const List<List_entry> &copy) {
	count = copy.count;
	Node<List_entry> *new_node, *old_node = copy.head;
	if (old_node == NULL)
	{
		head = NULL;
	}
	else {
		new_node = head = new Node<List_entry>(old_node->entry);
		while (old_node->next != NULL) {
			old_node = old_node->next;
			new_node->next = new Node<List_entry>(old_node->entry);
			new_node = new_node->next;
		}
	}
}
template <class List_entry>
void List<List_entry>::operator=(const List<List_entry> &copy) {
	List new_copy(copy);
	clear();
	count = new_copy.count;
	head = new_copy.head;
	new_copy.count = 0;
	new_copy.head = NULL;
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
	cout << "the list has " << c_list.size() << " items." << endl;
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
	cout << "clear the list, print its contents:" << endl;
	c_list.traverse(write_entry);
	cout << endl;
	cout << "enter characters and the program adds them to the list." << endl;
	cout << "use enter key to terminate the input." << endl;
	cout << "when listsize() is < 3, the element will be inserted at the back." << endl;
	while (!c_list.full() && (x = cin.get()) != '\n') {
		if (c_list.size() < 3)
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