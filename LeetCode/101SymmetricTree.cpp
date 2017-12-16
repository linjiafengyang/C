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
void TreeNodeCreate(TreeNode **tp) {
	// 构造方法，或者说构造顺序：从左子树开始构造
	int x;
	cin >> x;
	if(x < 0) {
		*tp = NULL;// 指针为空，树节点中的某个指针为空
		return;
	}
	*tp = (TreeNode*)malloc(sizeof(TreeNode));// 将树节点中指针指向该地址空间
	if(tp == NULL) return;
	(*tp)->val =x;
	TreeNodeCreate(&((*tp)->left));
	TreeNodeCreate(&((*tp)->right));
}

int main() {
	Solution s;
	TreeNode* tree;
	TreeNodeCreate(&tree);
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