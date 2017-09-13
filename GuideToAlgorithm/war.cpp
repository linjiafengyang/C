/*
突击战：n个部下，第i个部下需要你花Bi分钟交待任务，他会立刻执行Ji分钟后完成任务。你需要选择交待任务的顺序，使得所有任务尽早完成。
3
2 5
3 2
2 1

3
3 3
4 4
5 5

 */
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Job
{
	int j, b;
	bool operator<(const Job& x) const {
		return j > x.j;
	}
};
int main() {
	int n, b, j, Case = 1;
	while (scanf("%d", &n) == 1 && n) {
		vector<Job> v;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &b, &j);
			v.push_back((Job{j, b}));
		}
		sort(v.begin(), v.end());
		int s = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			s += v[i].b;
			ans = max(ans, s + v[i].j);
		}
		printf("Case %d: %d\n", Case++, ans);
	}
	return 0;
}