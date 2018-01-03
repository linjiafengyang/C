/**
  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 */
class Solution {
public:
	TreeNode* merge(TreeNode* T1, TreeNode* T2) {
		if(T1 == NULL) return T2;
		if(T2 == NULL) return T1;
		T1->val += T2->val;
		T1->left = merge(T1->left, T2->left);
		T1->right = merge(T1->right, T2->right);
		return T1;
	}
};
// another solution
class Solution {
public:
	TreeNode* merge(TreeNode* T1, TreeNode* T2) {
		if (!T1 && !T2) return NULL;
		if (!T1) return T2;
		if (!T2) return T1;
		TreeNode* T = new TreeNode(T1->val + T2->val);
		T->left = merge(T1->left, T2->left);
		T->right = merge(T1->right, T2->right);
		return T;
	}
};