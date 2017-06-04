#include <iostream>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
int in[1000001];
vector<int> v[1000001];
set<int> s;
void bfs() {
	while (!s.empty()) {
		int t = *s.begin();
		s.erase(s.begin());
		cout << t << " ";
		for (int i = 0; i < v[t].size(); i++) {
			int y = v[t][i];
			if (--in[y] == 0) {
				s.insert(y);
			}
		}
	}
	cout << endl;
}
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--) {
		int m, n;
		cin >> m >> n;
		memset(in, 0, sizeof(in));
		memset(v, 0, sizeof(v));
		s.clear();
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			in[y]++;
		}
		for (int i = 1; i <= m; i++) {
			if (!in[i]) s.insert(i);
		}
		bfs();
	}
	return 0;
}