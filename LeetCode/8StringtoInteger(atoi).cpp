/*
Implement atoi to convert a string to an integer.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 */
#include <iostream>
using namespace std;
class Solution {
public:
	int myAtoi(string str) {
		if (str.length() == 0) return 0;
		int i = 0, flag = 1;
		while (isspace(str[i])) i++;// 去掉空格
		if (str[i] == '+' || str[i] == '-') {
			if (str[i] == '-') flag = 0;// '-'做标记
			i++;
		}
		str = str.substr(i);// 去掉空格和符号位
		for (int j = 0; j < str.length(); j++) {
			if (!isdigit(str[j])) {
				str = str.substr(0, j);// 去掉数字后面的字符
				break;
			}
		}
		if (str.length() == 0) return 0;
		if (str.length() > 10) {
			if (flag == 0) return -2147483648;
			else return 2147483647;
		}
		long long int ans = stoll(str);
		if (flag == 0) ans = 0 - ans;
		if (ans > 2147483647) return 2147483647;
		else if (ans < -2147483648) return -2147483648;
		else return (int)ans;
	}
};
int main() {
	Solution s;
	string str;
	cin >> str;
	cout << s.myAtoi(str) << endl;
	return 0;
}