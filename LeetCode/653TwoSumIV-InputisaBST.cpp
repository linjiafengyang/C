/*
Given a Binary Search Tree and a target number, 
return true if there exist two elements in the BST 
such that their sum is equal to the given target.
 */
#include <iostream>
#include <set>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	bool findTarget(TreeNode* root, int k) {
		unordered_set<int> set;
		return dfs(root, set, k);
	}
	bool dfs(TreeNode* root, unordered_set<int>& set, int k) {
		if (root == NULL) return false;
		if (set.count(k - root->val)) return true;
		set.insert(root->val);
		return dfs(root->left, set, k) || dfs(root->right, set, k);
	}
};
// another version
class Solution {
public:
	bool findTarget(TreeNode* root, int k) {
		vector<int> nums;
		inorder(root, nums);
		int i = 0, j = nums.size() - 1;
		while (i < j) {
			if (nums[i] + nums[j] == k) return true;
			(nums[i] + nums[j] < k) ? i++ : j--;
		}
		return false;
	}
	// 将树的值放进vector里面，转换成167的处理方式
	void inorder(TreeNode* root, vector<int>& nums) {
		if (root == NULL) return;
		inorder(root->left, nums);
		nums.push_back(root->val);
		inorder(root->right, nums);
	}
};