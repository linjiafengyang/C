/*
我们在做dfs的时候，当访问到一个节点时，会出现四种情况：
1.此节点未被访问过，则此次的访问关系边（发起点——>接受点）称为树边（tree edge）；
2.此节点被访问过但此节点的子孙还没访问完，换句话说，此次的发起点的源头可以追溯到接收点，则此次访问关系边称为后向边（back edge）；
3.此节点被访问过且此节点的子孙已经访问完，而且发起点是搜索初始边，则称为前向边（down edge）；
4.此节点被访问过且此节点的子孙已经访问完，而且发起点不是搜索初始边，则称为横叉边（cross edge）。
其实这种分类只是相对的，也会随着dfs的改变而改变，比如搜索入口、搜索顺序等。

作者：Jreffery fei
链接：https://www.zhihu.com/question/20003218/answer/47081242
来源：知乎
著作权归作者所有，转载请联系作者获得授权。
 */
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int pre[101], post[101], edge[101][101], parent[101];
int tag;
void dfs_tag(int cur, int n) {
	pre[cur] = ++tag;
	for (int i = 0; i < n; i++) {
		if (edge[cur][i] == 1) {
			if (pre[i] == 0) {
				parent[i] = cur;
				edge[cur][i] = -1;
				dfs_tag(i, n);
			}
			else {
				if (post[i] == 0) edge[cur][i] = -2;
				else if (pre[i] > pre[cur]) edge[cur][i] = -3;
				else edge[cur][i] = -4;
			}
		}
	}
	post[cur] = ++tag;
}
void dfs(int n) {
	memset(pre, 0, sizeof(pre));
	memset(post, 0, sizeof(post));
	memset(parent, -1, sizeof(parent));
	for (int i = 0; i < n; i++) {
		if (parent[i] == -1) dfs_tag(i, n);
	}
}
int main(int argc, char const *argv[])
{
	int n, m;
	int u, v;
	int cases;
	tag = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		edge[u][v] = 1;
	}
	dfs(n);
	cin >> cases;
	while (cases--) {
		cin >> u >> v;
		switch (edge[u][v]) {
			case -1:
			cout << "edge (" << u << "," << v << ") is Tree Edge" << endl;
			break;
			case -2:
			cout << "edge (" << u << "," << v << ") is Back Edge" << endl;
			break;
			case -3:
			cout << "edge (" << u << "," << v << ") is Down Edge" << endl;
			break;
			default:
			cout << "edge (" << u << "," << v << ") is Cross Edge" << endl;
			break;
		}
	}
	return 0;
}