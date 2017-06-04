#include <iostream>
#include <queue>
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
void levelTraversal(BinaryNode<T> *root, void (*visit)(T &x)) {
	if (!root) return;
	queue<BinaryNode<T> *> dy;
	dy.push(root);
	BinaryNode<T> *p;
	while (!dy.empty()) {
		visit(dy.front()->elem);
		p = dy.front();
		dy.pop();
		if (p->left != NULL) dy.push(p->left);
		if (p->right != NULL) dy.push(p->right);
	}
}