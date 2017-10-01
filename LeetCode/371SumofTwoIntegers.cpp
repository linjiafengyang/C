/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.
 */
#include <iostream>
using namespace std;
// 递归
class Solution {
public:
	int getSum(int a, int b) {
		if (a == 0) return b;
		return getSum((a & b) << 1, a ^ b);
	}
};
// 非递归
class Solution {
public:
	int getSum(int a, int b) {
		while (a) {
			int x = a ^ b;
			a = (a & b) << 1;
			b = x;
		}
		return b;
	}
};
int main() {
	int a, b;
	cin >> a >> b;
	Solution s;
	cout << s.getSum(a, b) << endl;
	return 0;
}