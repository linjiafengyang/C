#include <iostream>
using namespace std;
template <typename E>
class LinkedList
{
public:
	LinkedList() {
		first = 0;
	}
	~LinkedList() {
		while (first != 0) {
			removeFirst();
		}
	}
	E getFirst() {
		return first->data;
	}
	bool isEmpty() {
		return first == 0;
	}
	LinkedList(const LinkedList &that);
	LinkedList& operator=(const LinkedList &that);
	void removeFirst();
	void addFirst(E data);
private:
	class Node {
	public:
		E data;
		Node *next;
	};
	Node *first;
};
template <typename E>
void LinkedList<E>::removeFirst() {
	Node *node = first;
	first = node->next;
	delete node;
}
template <typename E>
LinkedList<E>::LinkedList(const LinkedList<E> &that) {
	first = 0;
	*this = that;
}
template <typename E>
LinkedList<E>& LinkedList<E>::operator=(const LinkedList<E> &that) {
	if (this != &that) {
		while (first != 0) {
			removeFirst();
		}
		if (that.first != 0) {
			first = new Node;
			first->data = that.first->data;
			Node *p = first;
			Node *q = that.first->next;
			while (q != 0) {
				p->next = new Node;
				p->next->data = q->data;
				p = p->next;
				q = q->next;
			}
			p->next = 0;
		}
	}
	return *this;
}
template <typename E>
void LinkedList<E>::addFirst(E data) {
	if (first == 0) {
		first = new Node;
		first->data = data;
		first->next = 0;
	}
	else {
		Node *temp = new Node;
		temp->data = data;
		temp->next = first;
		first = temp;
	}
}