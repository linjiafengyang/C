#include <iostream>
using namespace std;
template <typename T>
struct BinaryNode
{
	T elem;
	BinaryNode *left;
	BinaryNode *right;
	BinaryNode(T d, BinaryNode *l = NULL, BinaryNode *r = NULL):elem(d), left(l), right(r) {};
};
template <typename T>
void inorder_recursive(BinaryNode<T> *root, void (*visit)(T &x)) {
	if (root != NULL) {
		inorder_recursive(root->left, visit);
		visit(root->elem);
		inorder_recursive(root->right, visit);
	}
}
template <typename T>
void inorder(BinaryNode<T> *root, void (*visit)(T &x)) {
	stack<BinaryNode<T> *> order;
	while ((root != NULL) || (!order.empty())) {
		while (root != NULL) {
			order.push(root);
			root = root->left;
		}
		if (!order.empty()) {
			root = order.top();
			order.pop();
			visit(root->elem);
			root = root->right;
		}
	}
}