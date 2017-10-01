/*
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

输入：9 9 9 9 
输出：1 0 0 0 0

输入：9 9 9 8
输出：9 9 9 9

输入：9 9 8 9
输出：9 9 9 9
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		for (int i = digits.size() - 1; i >= 0; i--) {
			if (digits[i] != 9) {
				digits[i]++;
				return digits;
			}
			digits[i] = 0;
		}
		digits.insert(digits.begin(), 1);
		return digits;
	}
};
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	Solution s;
	vector<int> result(n + 1);
	result = s.plusOne(a);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}