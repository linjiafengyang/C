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
		return sortedListToBST(head, NULL);
	}
private:
	TreeNode* sortedListToBST(ListNode* head, ListNode* tail) {
		if (head == tail) return NULL;
		if (head->next == tail) {
			TreeNode *root = new TreeNode(head->val);
			return root;
		}
		ListNode *mid = head, *temp = head;
		// 寻找中间节点
		while (temp != tail && temp->next != tail) {
			mid = mid->next;
			temp = temp->next->next;
		}
		TreeNode *root = new TreeNode(mid->val);
		root->left = sortedListToBST(head, mid);
		root->right = sortedListToBST(mid->next, tail);
		return root;
	}
};
