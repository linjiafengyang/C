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
	int minDepth(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		else if (root->left == NULL && root->right != NULL) {
			return minDepth(root->right) + 1;
		}
		else if (root->left != NULL && root->right == NULL) {
			return minDepth(root->left) + 1;
		}
		else {
			int leftDepth = minDepth(root->left) + 1;
			int rightDepth = minDepth(root->right) + 1;
			return leftDepth < rightDepth ? leftDepth : rightDepth;
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
	cout << s.minDepth(tree) << endl;
	return 0;
}