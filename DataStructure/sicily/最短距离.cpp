#include <iostream>
#include <string.h>
#define MAX 100000
using namespace std;
int map[101][101];
int dis[101];
bool visited[101];

void dijkstra(int begin, int end, int n) {
	for (int i = 0; i < n; i++) {
		dis[i] = map[begin][i];
	}
	visited[begin] = 1;
	int break_point = n - 1;
	while (break_point--) {
		int min = MAX, index;
		for (int i = 0; i < n; i++) {
			if (!visited[i] && min > dis[i]) {
				min = dis[i];
				index = i;
			}
		}
		visited[index] = 1;
		for (int j = 0; j < n; j++) {
			if (!visited[j] && min + map[index][j] < dis[j]) {
				dis[j] = map[index][j] + min;
			}
		}
	}
	if (dis[end] != MAX) cout << dis[end] << endl;
}
int main(int argc, char const *argv[])
{
	int test_case;
	cin >> test_case;
	while (test_case--) {
		int n, m, begin, end;
		cin >> n >> m >> begin >> end;
		memset(visited, 0, sizeof visited);
		memset(dis, 0, sizeof dis);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) map[i][j] = 0;
				else map[i][j] = MAX;
			}
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			map[a][b] = 1;
			map[b][a] = 1;
		}
		dijkstra(begin, end, n);
	}
	return 0;
}