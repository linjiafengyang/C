/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
 */
#include <iostream>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		string result;
		int len_a = a.length() - 1;
		int len_b = b.length() - 1;
		int extra = 0;
		char c;
		while (len_a >= 0 || len_b >= 0) {
			c = (a[len_a] - '0') + (b[len_b] - '0') + extra + '0';
			if (len_a > len_b && len_b < 0) { // a的长度比b长，例如11，1
				c = (a[len_a] - '0') + extra + '0';
			}
			else if (len_a < len_b && len_a < 0) { // 表示的长度比a长，例如1，11
				c = (b[len_b] - '0') + extra + '0';
			}
			extra = 0;// 进位
			if ((c - '0') >= 2) {// 进位判断
				extra = 1;
				c = c - 2;
			}
			result = c + result;// string连接
			len_a--;
			len_b--;
		}
		if (extra == 1) result = '1' + result;// 注意最前面可能还有进位，例如11，1
		return result;
	}
};
// another solution
class Solution {
public:
	string addBinary(string a, string b) {
		string result;
		int len_a = a.length() - 1;
		int len_b = b.length() - 1;
		int c = 0;
		while (len_a >= 0 || len_b >= 0 || c == 1) {
			c += len_a >= 0 ? a[len_a--] - '0' : 0;
			c += len_b >= 0 ? b[len_b--] - '0' : 0;
			result = char(c % 2 + '0') + result;
			c /= 2;
		}
		return result;
	}
};
int main() {
	Solution s;
	string a, b;
	cin >> a >> b;
	cout << s.addBinary(a, b) << endl;
	return 0;
}