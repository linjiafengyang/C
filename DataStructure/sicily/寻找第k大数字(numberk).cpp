#include <iostream>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > pq;
bool marked[20000002];
int main(int argc, char const *argv[])
{
	int n, k, data;
	cin >> n >> k;
	while (n--) {
		cin >> data;
		if (marked[data + 10000000]) continue;
		else {
			marked[data + 10000000] = true;
			pq.push(data);
		}
		if (pq.size() > k) pq.pop();
	}
	cout << pq.top() << endl;
	return 0;
}