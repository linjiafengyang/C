#include <iostream>
using namespace std;
const int max_list = 5000;
enum Error_code { success, fail, range_error, underflow, overflow, fatal,
                  not_present, duplicate_error, entry_inserted, entry_found,
                  internal_error };
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
	int count;
	List_entry entry[max_list];
};
template <class List_entry>
List<List_entry>::List() {
	count = 0;
}
template <class List_entry>
void List<List_entry>::clear() {
	count = 0;
}
template <class List_entry>
int List<List_entry>::size() const {
	return count;
}
template <class List_entry>
bool List<List_entry>::full() const {
	return count == max_list;
}
template <class List_entry>
bool List<List_entry>::empty() const {
	return count == 0;
}
template <class List_entry>
void List<List_entry>::traverse(void (*visit)(List_entry &)) {
	for (int i = 0; i < count; ++i)
	{
		(*visit)(entry[i]);
	}
}
template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x) {
	if (full())
	{
		return overflow;
	}
	if (position < 0 || position > count)
	{
		return range_error;
	}
	for (int i = count - 1; i >= position; i--) {
		entry[i + 1] = entry[i];
	}
	entry[position] = x;
	count++;
	return success;
}
template <class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x) const {
	if (position < 0 || position >= count)
	{
		return range_error;
	}
	x = entry[position];
	return success;
}
template <class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &x) {
	if (position < 0 || position >= count)
	{
		return range_error;
	}
	entry[position] = x;
	return success;
}
template <class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x) {
	if (count == 0)
	{
		return underflow;
	}
	if (position < 0 || position >= count)
	{
		return range_error;
	}
	x = entry[position];
	count--;
	while (position < count) {
		entry[position] = entry[position + 1];
		position++;
	}
	return success;
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
	cout << "when size() is 3, the element will be inserted at the front of the list" << endl;
	cout << "the other ones will appear at the back." << endl;
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
	return 0;
}