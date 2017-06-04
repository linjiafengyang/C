#include <iostream>
using namespace std;
typedef char Node_entry;
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
int main(int argc, char const *argv[])
{
	Node first_node('a');
	Node *p0 = &first_node;
	Node *p1 = new Node('b');
	p0->next = p1;
	Node *p2 = new Node('c', p0);
	p1->next = p2;
	cout << p0 << " " << p1 << " " << p2 << " " << endl;
	cout << p0->entry << " " << p1->entry << " " << p2->entry << " " << endl;
	cout << p0->next << " " << p1->next << " " << p2->next << " " << endl;
	return 0;
}