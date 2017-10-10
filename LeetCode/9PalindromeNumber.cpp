/*
Determine whether an integer is a palindrome. Do this without extra space.
判断回文数
 */
#include <iostream>
using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		// 负数以及以0结尾的数
		if (x < 0 || (x % 10 == 0 && x != 0)) {
			return false;
		}
		int reverseNumber = 0;
		// 循环结束条件：右边的数大于等于左边的数
		while (x > reverseNumber) {
			reverseNumber = reverseNumber * 10 + x % 10;
			x = x / 10;
		}
		// 两边数相等，如1221，此时x=12=reverseNumber;
		// 两边不相等，如12321，此时x=12，reverseNumber=123
		return x == reverseNumber || x == reverseNumber / 10;
	}
};
int main() {
	Solution s;
	int x;
	cin >> x;
	cout << s.isPalindrome(x) << endl;
	return 0;
}