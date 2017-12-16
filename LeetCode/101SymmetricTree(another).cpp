#include <iostream>
#include <malloc.h>
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
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		return isMirror(root->left, root->right);
	}
	bool isMirror(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL) return true;
		else if (p != NULL && q != NULL && p->val == q->val && isMirror(p->left, q->right) && isMirror(p->right, q->left))
			return true;
		else return false;
	}
};
// 构造二叉树
int TreeNodeCreate(TreeNode* &tree) {
	int val;
	cin >> val;
	if (val < 0) // 小于0表示空节点
		tree = NULL;
	else {
		tree = new TreeNode(val); // 创建根节点
		tree->val = val;
		TreeNodeCreate(tree->left); // 创建左子树
		TreeNodeCreate(tree->right);// 创建右子树
	}
	return 0;
}
int main() {
	Solution s;
	TreeNode* tree;
	TreeNodeCreate(tree);
	cout << s.isSymmetric(tree) << endl;
	return 0;
}
/*
input:
1
2
3
-1 -1
4
-1 -1
2
4
-1 -1
3
-1 -1

output:
1
 */

/*
input:
1
2
-1
3
-1 -1
2
-1 3
-1 -1

output:
0
 */