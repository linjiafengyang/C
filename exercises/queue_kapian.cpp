/*
队列：卡片游戏：至少还有两张牌时，把第一张牌拿掉，把新的第一张牌拿到整副牌的最后
 */
#include <iostream>
#include <queue>
using namespace std;
int main() {
	int n;
	queue<int> q;
	cin >> n;
	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
		q.push(q.front());
		q.pop();
	}
	return 0;
}