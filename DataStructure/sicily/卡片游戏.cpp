#include <iostream>
#include <queue>
using namespace std;
int main(int argc, char const *argv[])
{
	queue<int> q;
	int t;
	int n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			q.push(i + 1);
		}
		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop();
			q.push(q.front());
			q.pop();
		}
	}
	return 0;
}