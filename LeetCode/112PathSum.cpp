#include <iostream>
#include <vector>
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
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL) return false;
		if (root->left == NULL && root->right == NULL) return sum == root->val ? true : false;
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};
void preorder(TreeNode* root) {
	if (root == NULL) cout << "null" << " ";
	else {
		cout << root->val << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

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
	int sum;
	cin >> sum;
	cout << s.hasPathSum(tree, sum) << endl;
	return 0;
}