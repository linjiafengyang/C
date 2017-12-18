#include <iostream>
#include <vector>
#include <malloc.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
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
	TreeNode* sortedListToBST(ListNode* head) {
		if (head == NULL) return NULL;
		if (head->next == NULL) return new TreeNode(head->val);
		int cnt = 0;
		vector<int> v;
		ListNode* temp = head;
		while (temp != NULL) {
			v.push_back(temp->val);
			temp = temp->next;
			cnt++;
		}
		return sortedArrayToBST(v);
	}
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
// 创建链表（头结点无效）
ListNode* createList() {
	ListNode *head, *tail;
	head = (ListNode*)malloc(sizeof(ListNode));// 分配一个不存放有效数据的头结点
	tail = head;// 链表的最后一个节点
	tail->next = NULL;// 最后一个节点的指针置为空
	int n;// 节点个数
	cin >> n;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		// 为节点分配空间
		ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
		temp->val = val;// 将用户输入的数据赋给节点的成员
		tail->next = temp;// 将最后一个节点的指针指向下一个新的节点
		temp->next = NULL;// 将新节点中的指针置为空
		tail = temp;// 将新节点赋给最后的一个节点
	}
	return head;// 返回头节点
}
int main() {
	Solution s;
	ListNode* head = createList();
	cout << head->val << endl;
	TreeNode* root = s.sortedListToBST(head);
	preorder(root);
	return 0;
}
