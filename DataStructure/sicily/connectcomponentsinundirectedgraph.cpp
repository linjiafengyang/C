#include <iostream>
#include <queue>
using namespace std;
bool path[1001][1001];
bool visited[1001];
int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int node1, node2;
		cin >> node1 >> node2;
		path[node1][node2] = true;
		path[node2][node1] = true;
	}
	for (int i = 1; i <= n; i++) {
		visited[i] = false;
	}
	int count = 0;
	int temp = n;
	while (temp--) {
		queue<int> store;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				store.push(i);
				count++;
				visited[i] = true;
				break;
			}
		}
		while (!store.empty()) {
			for (int i = 1; i <= n; i++) {
				if (path[store.front()][i] && !visited[i]) {
					store.push(i);
					visited[i] = true;
				}
			}
			store.pop();
		}
	}
	cout << count << endl;
	return 0;
}