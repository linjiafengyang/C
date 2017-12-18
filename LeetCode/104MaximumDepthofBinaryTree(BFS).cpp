#include <iostream>
#include <queue>
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
		if (root == NULL) return 0;
		int res = 0;
		queue<TreeNode *> q;
		q.push(root);
		while (!q.empty()) {
			res++;
			int n = q.size();
			for (int i = 0; i < n; i++) {
				TreeNode *p = q.front();
				q.pop();
				if (p->left != NULL) q.push(p->left);
				if (p->right != NULL) q.push(p->right);
			}
		}
		return res;
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