#include <iostream>
using namespace std;
struct Node
{
	Node *next;
	int data;
};
Node* Create(int n) {
	Node *head = new Node;
	Node *p, *pre;
	head->next = NULL;
	head->data = 1;
	pre = head;
	for (int i = 2; i <= n; ++i)
	{
		p = new Node;
		p->data = i;
		p->next = NULL;
		pre->next = p;
		pre = p;
	}
	pre->next = head;
	return head;
}
void chooseKing(Node *h, int M) {
	int count;
	while (h->next != h) {
		count = 1;
		while (count < M - 1) {
			h = h->next;
			count++;
		}
		Node *q = h->next;
		h->next = h->next->next;
		h = h->next;
		delete q;
	}
	cout << h->data << endl;
	delete h;
}
int main(int argc, char const *argv[])
{
	int m;
	cin >> m;
	while (m--) {
		int n, M;
		cin >> n >> M;
		Node *h = Create(n);
		chooseKing(h, M);
	}
	return 0;
}