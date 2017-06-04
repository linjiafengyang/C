#include <iostream>
using namespace std;
enum Error_code { success, fail, range_error, underflow, overflow, fatal,
                  not_present, duplicate_error, entry_inserted, entry_found,
                  internal_error };
template <class Node_entry>
struct Node {
	Node_entry entry;
	Node<Node_entry> *next;
	Node<Node_entry> *back;
	Node();
	Node(Node_entry, Node<Node_entry> *link_back = NULL, Node<Node_entry> *link_next = NULL);
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
	mutable int current_position;
	mutable Node<List_entry> *current;
	void set_position(int position) const;
	Node<List_entry> *first, *last;
};

template <class List_entry>
Node<List_entry>::Node() {
	next = back = NULL;
}
template <class List_entry>
Node<List_entry>::Node(List_entry data, Node<List_entry> *link_back, Node<List_entry> *link_next) {
	entry = data;
	back = link_back;
	next = link_next;
}

template <class List_entry>
List<List_entry>::List() {
	count = 0;
	current = first = last = NULL;
	current_position = -1;
}
template <class List_entry>
void List<List_entry>::clear() {
	Node<List_entry> *p;
	while (first) {
		p = first->next;
		delete first;
		first = p;
	}
	count = 0;
	current = first = last = NULL;
	current_position = -1;
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
	return false;
}
template <class List_entry>
void List<List_entry>::traverse(void (*visit)(List_entry &)) {
	Node<List_entry> *to_visit = first;
	for (; to_visit; to_visit = to_visit->next) {
		(*visit)(to_visit->entry);
	}
}
template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x) {
	Node<List_entry> *new_node, *following, *preceding;
	if (position < 0 || position > count)
	{
		return range_error;
	}
	if (position == 0)
	{
		if (count == 0)
		{
			following = NULL;
		}
		else {
			set_position(0);
			following = current;
		}
		preceding = NULL;
	}
	else {
		set_position(position - 1);
		preceding = current;
		following = preceding->next;
	}
	new_node = new Node<List_entry>(x, preceding, following);
	if (new_node == NULL)
	{
		return overflow;
	}
	if (preceding != NULL)
	{
		preceding->next = new_node;
	}
	if (following != NULL)
	{
		following->back = new_node;
	}
	current = new_node;
	current_position = position;
	if (new_node->back == NULL)
	{
		first = new_node;
	}
	if (new_node->next == NULL)
	{
		last = new_node;
	}
	count++;
	return success;
}
template <class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x) const {
	if (position < 0 || position >= count)
	{
		return range_error;
	}
	set_position(position);
	x = current->entry;
	return success;
}
template <class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &x) {
	if (position < 0 || position >= count)
	{
		return range_error;
	}
	set_position(position);
	current->entry = x;
	return success;
}
template <class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x) {
	Node<List_entry> *old_node, *neighbor;
	if (count == 0)
	{
		return fail;
	}
	if (position < 0 || position >= count)
	{
		return range_error;
	}
	set_position(position);
	old_node = current;
	if (neighbor = current->back)
	{
		neighbor->next = current->next;
	}
	if (neighbor = current->next)
	{
		neighbor->back = current->back;
		current = neighbor;
	}
	else {
		current = current->back;
		current_position--;
	}
	x = old_node->entry;
	delete old_node;
	count--;
	if (current->next == NULL)
	{
		last = current;
	}
	if (current->back == NULL)
	{
		first = current;
	}
	return success;
}
template <class List_entry>
void List<List_entry>::set_position(int position) const {
	if (current_position <= position)
	{
		if (position >= count / 2)
		{
			if (count - position <= position - current_position)
			{
				current_position = count - 1;
				current = last;
				for (; current_position != position; current_position--) {
					current = current->back;
				}
			}
			else {
				for (; current_position != position; current_position++) {
					current = current->next;
				}
			}
		}
		else {
			for (; current_position != position; current_position++) {
				current = current->next;
			}
		}
	}
	else {
		if (position >= count / 2)
		{
			for (; current_position != position; current_position--) {
				current = current->back;
			}
		}
		else {
			if (current_position - position <= position)
			{
				for (; current_position != position; current_position--) {
					current = current->back;
				}
			}
			else {
				current_position = 0;
				current = first;
				for (; current_position != position; current_position++) {
					current = current->next;
				}
			}
		}
	}
}
template <class List_entry>
List<List_entry>::~List() {
	clear();
}
template <class List_entry>
List<List_entry>::List(const List<List_entry> &copy) {
	count = copy.count;
	current_position = copy.current_position;
	Node<List_entry> *new_node, *old_node = copy.current;
	if (old_node == NULL)
	{
		current = NULL;
	}
	else {
		new_node = current = new Node<List_entry>(old_node->entry);
		while (old_node->next != NULL) {
			old_node = old_node->next;
			new_node->next = new Node<List_entry>(old_node->entry, new_node);
			new_node = new_node->next;
		}
		old_node = copy.current;
		new_node = current;
		while (old_node->back != NULL) {
			old_node = old_node->back;
			new_node->back = new Node<List_entry>(old_node->entry, NULL, new_node);
			new_node = new_node->back;
		}
	}
}
template <class List_entry>
void List<List_entry>::operator=(const List<List_entry> &copy) {
	List new_copy(copy);
	clear();
	count = new_copy.count;
	current_position = new_copy.current_position;
	current = new_copy.current;
	new_copy.count = 0;
	new_copy.current_position = 0;
	new_copy.current = NULL;
}

void write_entry(char &c) {
	cout << c;
}
void show_help() {
	cout << "------------------\n";
	cout << " A: Append        \n";
	cout << " I: Insert        \n";
	cout << " C: Clear         \n";
	cout << " D: Delete        \n";
	cout << " R: Replace       \n";
	cout << " F: Fetch         \n";
	cout << " T: Traverse      \n";
	cout << " S: Return size   \n";
	cout << " H: This Help     \n";
	cout << " Q: Quit          \n";
	cout << "------------------\n";
}
char get_command() {
	char cmd;
	bool waiting = true;
	cout << "#: ";

	while (waiting) {
		cin >> cmd;
		cmd = tolower(cmd);

		if (cmd == 'a' || cmd == 'i' || cmd == 'd' ||
			 cmd == 'r' || cmd == 'f' || cmd == 't' ||
			 cmd == 's' || cmd == 'h' || cmd == 'q' ||
			 cmd == 'c')	waiting = false;

		else
			show_help();
	}
	return cmd;
}
bool do_command(char cmd,List<char> &c_list) {

	char x;
	int i;
	switch(cmd) {
	case 'a':
		cout << "Append: ";
		cin >> x;
		c_list.insert(c_list.size(),x);
		break;
	case 'i':
		cout << "Insert what? ";
		cin >> x;
		cout << "Where? ";
		cin >> i;
		if (c_list.insert(i,x) != success)
			cout << "Error!" << endl;
		break;
	case 'd':
		cout << "Delete where? ";
		cin >> i;
		if (c_list.remove(i,x) != success)
			cout << "Error!" << endl;
		break;
	case 'r':
		cout << "Replace where? ";
		cin >> i;
		cout << "With what? ";
		cin >> x;
		if (c_list.replace(i,x) != success)
			 cout << "Error!" << endl;
		break;
	case 'f':
		cout << "Fetch where? ";
		cin >> i;
		if (c_list.retrieve(i,x) == success)
			cout << "Fetched " << x << " from " << i << endl;
		else
			cout << "Error!" << endl;
		break;
	case 't':
		cout << "Traverse: ";
		if (c_list.size())
			c_list.traverse(write_entry);
		else
			cout << "<empty>";
		cout << endl;
		break;
	case 's':
		cout << "Size: " << c_list.size() << endl;
		break;
	case 'h':
		show_help();
		break;
	case 'c':
		c_list.clear();
		cout << "List cleared." << endl;
		break;
	case 'q':
		return false;
		break;
	}
	return true;
}
int main(int argc, char const *argv[])
{
	List<char> c_list;
	cout << "doubly linked list program and tester" << endl;
	show_help();
	while (do_command(get_command(), c_list));
	return 0;
}