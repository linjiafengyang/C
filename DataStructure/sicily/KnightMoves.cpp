#include <iostream>
#include <queue>
#include <string.h>
#include <stdio.h>
using namespace std;
bool maze[8][8];
struct p
{
	int x, y, step;
	p(int a, int b, int s = 0):x(a), y(b), step(s) {}
};
int bfs(p start, p end) {
	if (start.x == end.x && start.y == end.y) return 0;
	int dir[][2] = {{1, 2}, {-1, 2}, {2, 1}, {-2, 1}, {1, -2}, {-1, -2}, {2, -1}, {-2, -1}};
	queue<p> dy;
	dy.push(start);
	maze[start.x][start.y] = 1;
	while (!dy.empty()) {
		p t = dy.front();
		dy.pop();
		for (int i = 0; i < 8; i++) {
			p next(t.x + dir[i][0], t.y + dir[i][1], t.step + 1);
			if (next.x == end.x && next.y == end.y) return next.step;
			if (next.x >= 0 && next.y >= 0 && next.x <= 7 && next.y <= 7 && maze[next.x][next.y] == 0) {
				dy.push(next);
				maze[next.x][next.y] = 1;
			}
		}
	}
	return -1;
}
int main(int argc, char const *argv[])
{
	int n, i;
	string a, b;
	cin >> n;
	while (n--) {
		memset(maze, 0, sizeof(maze));
		cin >> a >> b;
		p start(a[1] - '1', a[0] - 'a');
		p end(b[1] - '1', b[0] - 'a');
		cout << "To get from " << a << " to " << b << " takes " << bfs(start, end) << " knight moves." << endl;
	}
	return 0;
}