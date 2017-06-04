#include <iostream>
#include <queue>
using namespace std;
int a[1005][1005], res[1005];
bool visited[1005];
int n, m;
void bfs() {
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	res[1] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (a[now][i] && !visited[i]) {
				res[i] = res[now] + 1;
				visited[i] = 1;
				q.push(i);
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int temp1, temp2;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> temp1 >> temp2;
		a[temp1][temp2] = a[temp2][temp1] = 1;
	}
	for (int i = 1; i <= n; i++) {
		res[i] = -1;
	}
	bfs();
	for (int i = 1; i <= n; i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}