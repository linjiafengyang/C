#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		// return (p != NULL && q != NULL && p->val == q->val 
		// 	&& isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) 
		// 	|| (p == NULL && q == NULL);

		if (p == NULL && q == NULL) return true;
		else if (p != NULL && q != NULL && p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) 
			return true;
		else return false;
	}
};
int main() {
	Solution s;

	int val1;
	cin >> val1;
	TreeNode tree1(val1);

	int left1;
	cin >> left1;
	TreeNode l1(left1);

	int right1;
	cin >> right1;
	TreeNode r1(right1);
	// 构造指向结构体的指针
	TreeNode* p;
	p = &tree1;
	p->left = &l1;
	p->right = &r1;

	int val2;
	cin >> val2;
	TreeNode tree2(val2);
	

	int left2;
	cin >> left2;
	TreeNode l2(left2);

	int right2;
	cin >> right2;
	TreeNode r2(right2);
	// 构造指向结构体的指针
	TreeNode* q;
	q = &tree2;
	q->left = &l2;
	q->right = &r2;
	cout << s.isSameTree(p, q) << endl;
	return 0;
}