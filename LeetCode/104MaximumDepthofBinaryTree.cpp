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
	int maxDepth(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		// 可以简化
		// else if (root->left == NULL && root->right == NULL) {
		// 	return 1;
		// }
		// else if (root->left != NULL && root->right == NULL) {
		// 	return maxDepth(root->left) + 1;
		// }
		// else if (root->left == NULL && root->right != NULL) {
		// 	return maxDepth(root->right) + 1;
		// }
		else {
			int leftDepth = maxDepth(root->left) + 1;
			int rightDepth = maxDepth(root->right) + 1;
			return leftDepth > rightDepth ? leftDepth : rightDepth;
		}
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
	cout << s.maxDepth(tree) << endl;
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
3
 */