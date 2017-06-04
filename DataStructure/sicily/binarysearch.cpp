#include <iostream>
using namespace std;
int binSearch(const int s[], const int size, const int target) {
	int n = size;
	if (n <= 0) return -1;
	int low = 0, high = n - 1;
	while (low < high) {
/*
这里中间位置的计算就不能用low+((high-low)>>1)了，因为当low+1等于high
且A[low] <= target时，会死循环；所以这里要使用low+((high-low+1)>>1)，
这样能够保证循环会正常结束。
*/ 
		int mid = low + ((high - low + 1) >> 1);
		if (s[mid] > target) high = mid - 1;
		else low = mid;
	}
/*
循环过程中，当high小于n-1时，A[high+1]是大于target的，因为A[mid] > target时，
high=mid-1；当low大于0时，A[low]是小于等于target的，因为A[mid] <= target时，
low = mid；循环结束时，low 等于 high，所以，如果A[high](A[low])等于target，
那么high(low)就是target出现的最大位置，否则target在数组中不存在。
*/ 
	if (s[high] != target) return -1;
	else return high;
}
int main(int argc, char const *argv[])
{
	int s[8] = {0, 1, 1, 3, 3, 3, 6, 6};
	cout << binSearch(s, 8, 3) << endl;
	cout << binSearch(s, 8, 4) << endl;
	return 0;
}