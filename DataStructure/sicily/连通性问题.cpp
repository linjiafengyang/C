#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
/*
int main(int argc, char const *argv[])
{
	int a, b;
	int t, k1, k2;
	queue<int> q[10001];
	int exist[100001];
	memset(exist, -1, sizeof(exist));
	while (scanf("%d%d", &a, &b) != EOF) {
		if (exist[a] == -1 && exist[b] == -1) {
			t = 0;
			while (!q[t].empty()) t++;
			q[t].push(a);
			q[t].push(b);
			exist[a] = t;
			exist[b] = t;
			printf("%d %d\n", a, b);
		}
		else if (exist[a] != -1 && exist[b] != -1) {
			if (exist[a] == exist[b]) continue;
			t = exist[b];
			while (!q[t].empty()) {
				q[exist[a]].push(q[t].front());
				exist[q[t].front()] = exist[a];
				q[t].pop();
			}
			printf("%d %d\n", a, b);
		}
		else {
			k1 = exist[a] != -1 ? a : b;
			k2 = exist[b] != -1 ? a : b;
			q[exist[k1]].push(k2);
			exist[k2] = exist[k1];
			printf("%d %d\n", a, b);
		}
	}
	return 0;
}
*/
#define Max 100001
int data[Max];

int find(int num) {
	return (num == data[num] ? num : data[num] = find(data[num]));
}
int main(int argc, char const *argv[])
{
	for (int i = 0; i < Max; i++) {
		data[i] = i;
	}
	int point1, point2;
	while (cin >> point1 >> point2) {
		int p = find(point1);
		int q = find(point2);
		if (p != q) {
			cout << point1 << " " << point2 << endl;
			data[p] = data[q];
		}
	}
	return 0;
}