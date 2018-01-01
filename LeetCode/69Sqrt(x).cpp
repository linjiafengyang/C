#include <iostream>
using namespace std;
// bad solution
class Solution {
public:
	int mySqrt(int x) {
		if (x == 0) return 0;
		for (long i = 1; i <= x; i++) {
			if (i * i <= x && (i + 1) * (i + 1) > x) {
				return (int)i;
			}
		}
	}
};
// another solution
class Solution {
public:
    int mySqrt(int x) {
        long left = 0, right = INT_MAX, mid = 0;
        while (true) {
            long mid = left + (right - left) / 2;
            if (mid * mid <= x && (mid + 1) * (mid + 1) > x)
                return (int)mid;
            if (mid * mid < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
};
int main() {
	int x;
	Solution s;
	cin >> x;
	cout << s.mySqrt(x) << endl;
	return 0;
}