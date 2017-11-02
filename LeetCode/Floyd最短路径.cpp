/*
input:
4 8   
1 2 2   
1 3 6   
1 4 4   
2 3 3   
3 1 7   
3 4 1   
4 1 5   
4 3 12

output:
0 2 5 4
9 0 3 4
6 8 0 1
5 7 10 0
 */
#include <iostream>
using namespace std;

const int INF = 99999;

int main() {
	int edges[10][10];
	int v, e;
	int a, b;
	int num;
	cin >> v >> e;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j) edges[i][j] = 0;
			else edges[i][j] = INF;
		}
	}
	for (int i = 1; i <= e; i++) {
		cin >> a >> b >> num;
		edges[a][b] = num;
		//edges[b][a] = num;
	}
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (edges[i][j] > (edges[i][k] + edges[k][j])) {
					edges[i][j] = edges[i][k] + edges[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			cout << edges[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
