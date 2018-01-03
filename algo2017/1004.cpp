#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// class Solution {
// public:
// 	vector<int> topologicalSort(int n, vector<pair<int, int>>& edges) {
// 		vector<int> res;
// 		int *inDegree = new int[n];// 记录每个点的入度
// 		bool *havePop = new bool[n];// 记录某个点是否已经被输出
// 		for (int i = 0; i < n; i++) {
// 			inDegree[i] = 0;
// 			havePop[i] = false;
// 		}

// 		for (int i = 0; i < edges.size(); i++) {
// 			inDegree[edges[i].second]++;
// 		}

// 		int temp = n;
// 		while (temp > 0) {
// 			int present;
// 			for (int i = 0; i < n; i++) {// 找到一个入度为0的点
// 				if (inDegree[i] == 0 && havePop[i] == false) {
// 					present = i;
// 					break;
// 				}
// 			}

// 			for (int i = 0; i < edges.size(); i++) {
// 				if (edges[i].first == present) {
// 					inDegree[edges[i].second]--;
// 				}
// 			}
// 			havePop[present] = true;
// 			res.push_back(present);
// 			temp--;
// 		}
// 		return res;
// 	}
// };
class Solution {
public:
	vector<int> topologicalSort(int n, vector<pair<int, int>>& edges) {
		vector<int> res;
		int *inDegree = new int[n];// 记录每个点的入度
		for (int i = 0; i < n; i++) {
			inDegree[i] = 0;
		}

		queue<int> inDegreeZero;// 存储入度为0的点
		vector<vector<int>> reach(n);// 存储邻接表
		for (int i = 0; i < edges.size(); i++) {
			inDegree[edges[i].second]++;// 记录每个点的入度
			reach[edges[i].first].push_back(edges[i].second);// 把每条边存储成邻接表
		}
		for (int i = 0; i < n; i++) {
			if (inDegree[i] == 0) 
				inDegreeZero.push(i);// 存储入度为0的点
		}

		while (res.size() < n) {
			int present = inDegreeZero.front();// 每次取队列的第一个元素输出
			for (int i = 0; i < reach[present].size(); i++) {// 从入度为0的点开始，遍历该点连接的边
				// 判断更新完连接点的入度是否为0，是则加入队列
				int temp = (--inDegree[reach[present][i]]);
				if (temp == 0) {
					inDegreeZero.push(reach[present][i]);
				}
			}
			inDegreeZero.pop();
			res.push_back(present);
		}
		return res;
	}
};
int main() {
	Solution s;
	pair<int, int> p;
	vector<pair<int, int>> edges;
	int n;
	cin >> n;
	for (int i = 0; i < 4; i++) {// 这里只能自己动手修改输入的边数
		cin >> p.first >> p.second;
		edges.push_back(p);
	}
	vector<int> res = s.topologicalSort(n, edges);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	return 0;
}