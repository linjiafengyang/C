#include <iostream>
#include <vector>
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
	vector<vector<int> > pathSum(TreeNode* root, int sum) {
		vector<vector<int> > paths;
		vector<int> path;
		findPaths(root, sum, path, paths);
		return paths;
	}
private:
	void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
		if (node == NULL) return;
		path.push_back(node->val);
		if (node->left == NULL && node->right == NULL && sum == node->val)
			paths.push_back(path);
		findPaths(node->left, sum - node->val, path, paths);
		findPaths(node->right, sum - node->val, path, paths);
		path.pop_back();
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
	int sum;
	cin >> sum;
	vector<vector<int> > res = s.pathSum(tree, sum);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
/*
input:
5
4
11
7
-1 -1
2
-1 -1
-1
8
13
-1 -1
4
5
-1 -1
1
-1 -1

22

output:
5 4 11 2
5 8 4 5
 */