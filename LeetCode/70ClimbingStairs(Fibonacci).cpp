#include <iostream>
using namespace std;
class Solution {
public:
	int climbStairs(int n) {
		if (n == 1) return 1;
		int first = 1;
		int second = 2;
		for (int i = 3; i <= n; i++) {
			int third = first + second;
			first = second;
			second = third;
		}
		return second;
	}
};
int main() {
	int n;
	cin >> n;
	Solution s;
	cout << s.climbStairs(n) << endl;
	return 0;
}