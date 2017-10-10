/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
 */
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	string intToRoman(int num) {
		// 列举出罗马数字可能组成的表示
		string c[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
		// 罗马数字可能组成的数字大小
		int n[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

		string ans;
		int index = 0;
		int cnt;
		
		while (num > 0) {
			// 数字的个数，例如20，为两个n[8]=10，则cnt=2，ans加了两个X
			cnt = num / n[index];
			while (cnt--) {
				ans += c[index];
			}
			num %= n[index];
			index++;
		}
		return ans;
	}
};
int main() {
	int num;
	Solution so;
	cin >> num;
	cout << so.intToRoman(num) << endl;
	return 0;
}