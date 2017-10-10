/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
 */
#include <iostream>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
	int romanToInt(string s) {
		map<char, int> m;// 利用map对应罗马数字和数字
		// 罗马数字 对应 数字
		char c[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
		int n[] = {1, 5, 10, 50, 100, 500, 1000};
		// 存储该对应关系
		for (int i = 0; i < 7; i++) {
			m.insert(pair<char, int>(c[i], n[i]));
		}
		int ans = 0;
		for (int i = 0; i < s.length() - 1; i++) {
			// 这里需要了解一下罗马数字的表示方法
			// 比如IV表示是4，为-I+V（-1+5）
			// 比如VI表示是6，为V+I（5+1）
			if (m[s[i]] >= m[s[i + 1]]) {
				ans += m[s[i]];
			}
			else {
				ans -= m[s[i]];
			}
		}
		// 不要忘记s的最后一个字符
		ans += m[s[s.length() - 1]];
		return ans;
	}
};
int main() {
	string s;
	Solution so;
	cin >> s;
	cout << so.romanToInt(s) << endl;
	return 0;
}