#include <iostream>
#include <cmath>
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
	bool isBalanced(TreeNode* root) {
		if (root == NULL) {
			return true;
		}
		else {
			int left = maxDepth(root->left);// 左子树深度
			int right = maxDepth(root->right);// 右子树深度
			// 注意这里依然需要递归左子树、右子树
			return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
		}
	}
	int maxDepth(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
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
	cout << s.isBalanced(tree) << endl;
	return 0;
}
