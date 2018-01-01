#include <iostream>
using namespace std;
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
// Time Limit Exceeded
class Solution {
public:
    int firstBadVersion(int n) {
        for (int i = 1; i < n; i++) {
        	if (isBadVersion(i)) 
        		return i;
        }
        return n;
    }
};
