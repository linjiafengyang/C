#include <iostream>
using namespace std;
struct ListNode
{
	int data;
	ListNode *next;
};
//链表类接口如下：
class List
{
public:
 	List() {
		head = new ListNode;
		head->next = NULL;
	}
	~List() {
		ListNode* curNode;
		while( head->next ) {
			curNode = head->next;
			head->next = curNode->next;
			delete curNode;
		}
		delete head;
	}
//在链表第pos(pos>0)个结点之前插入新结点，新结点的值为toadd
//链表实际结点从1开始计数。
//调用时需保证pos小等于链表实际结点数 
	void insert(int toadd, int pos);
//删除链表的第pos(pos>0)个结点 
//链表实际结点从1开始计数。
//调用时需保证pos小等于链表实际结点数 
	void remove(int pos);
// Data field
	ListNode *head; //head指向虚拟头结点，head-next指向第一个实际结点
};
void List::insert(int toadd, int pos) {
	int count;
	ListNode *temp = head;
	while (temp->next) {
		temp = temp->next;
		count++;
	}
	count++;
	if (pos > 0 && pos <= count)
	{
		ListNode *temp2 = new ListNode;
		temp2->data = toadd;
		if (pos == 1)
		{
			temp2->next = head->next;
			head->next = temp2;
		}
		else {
			ListNode *temp1 = head;
			for (int i = 0; i < pos - 1; ++i)
			{
				temp1 = temp1->next;
			}
			temp2->next = temp1->next;
			temp1->next = temp2;
		}
	}
}
void List::remove(int pos) {
	int count = 0;
	ListNode *temp = head;
	while (temp->next) {
		temp = temp->next;
		count++;
	}
	if (pos > 0 && pos <= count)
	{
		ListNode *temp2;
		temp->next = NULL;
		if (pos == 1)
		{
			temp2 = head->next;
			head->next = temp2->next;
			delete temp2;
		}
		else {
			ListNode *temp1 = head;
			for (int i = 0; i < pos - 1; ++i)
			{
				temp1 = temp1->next;
			}
			temp2 = temp1->next;
			temp1->next = temp2->next;
			delete temp2;
		}
	}
}