#include <iostream>
using namespace std;
struct ListNode
{
	int data;
	ListNode *next;
};
class List {
public:
	List() {
		head = new ListNode;
		head->next = NULL;
	}
	~List() {
		ListNode* curNode;
		while (head->next) {
			curNode = head->next;
			head->next = curNode->next;
			delete curNode;
		}
		delete head;
	}
	void insert(int toadd, int pos);
	ListNode *head;
};
void List::insert(int toadd, int pos) {
	int count = 0;
	ListNode *temp = head;
	while (temp->next) {
		temp = temp->next;
		count++;
	}
	count++;
	if (pos > 0 && pos <= count) {
		ListNode *temp2 = new ListNode;
		temp2->data = toadd;
		if (pos == 1) {
			temp2->next = head->next;
			head->next = temp2;
		}
		else {
			ListNode *temp1 = head;
			for (int i = 0; i < pos - 1; i++) {
				temp1 = temp1->next;
			}
			temp2->next = temp1->next;
			temp1->next = temp2;
		}
	}
}