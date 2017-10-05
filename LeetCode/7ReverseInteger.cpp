/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
 */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		string s = to_string(x);//C++11
		if (s[0] == '-') std::reverse(s.begin() + 1, s.end());
		else std::reverse(s.begin(), s.end());
		long long int temp = stoll(s);// C++11: stoi = string to int; stol = string to long; stoll = string to long long
		if (temp > 2147483647 || temp < -2147483648) return 0;
		return (int)temp;
	}
};
//another version
class Solution {
public:
	int reverse(int x) {
		long long res = 0;
		while (x) {
			res = res * 10 + x % 10;
			x /= 10;
		}
		return (res < INT_MIN || res > INT_MAX) ? 0 : (int)res;
	}
};
int main() {
	Solution s;
	int x;
	cin >> x;
	cout << s.reverse(x) << endl;
	return 0;
}