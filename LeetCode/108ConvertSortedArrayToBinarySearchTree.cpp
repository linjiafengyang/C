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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0) return NULL;
		if (nums.size() == 1) return new TreeNode(nums[0]);
		// 根节点
		int middle = nums.size() / 2;
		TreeNode* root = new TreeNode(nums[middle]);
		// 左子树/右子树
		vector<int> leftVectors(nums.begin(), nums.begin() + middle);
		vector<int> rightVectors(nums.begin() + middle + 1, nums.end());
		// 递归
		root->left = sortedArrayToBST(leftVectors);
		root->right = sortedArrayToBST(rightVectors);
		return root;
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
int main() {
	Solution s;
	vector<int> nums;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}
	TreeNode* root = s.sortedArrayToBST(nums);
	preorder(root);
	return 0;
}