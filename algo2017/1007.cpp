#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
// class Solution {
// public:
//     int minLeftMonsters(vector<vector<char> > G) {
//         int sum = G.size();
//         vector<int> rest;
//         for (int i = 0; i < sum; i++)  // 最开始所有的怪兽都还存活
//             rest.push_back(i);
//         int res = findMin(G, rest, sum);
//         return res;
//     }

//     int findMin(vector<vector<char> > G, vector<int> rest, int restNum) {
//         vector<vector<char> > g;
//         int min = restNum;
//         int tmpMin = min;
//         if (G.size() == 0) return min;
//         for (int i = 0; i < restNum; i++) {  // 罗列出两两所有情况，可能会有重复的rest结果
//             for (int j = i + 1; j < restNum; j++) {
//                 vector<int> tmp = rest;
//                 if (G[i][j] == '+') {  // 这个怪兽会被杀死
//                     tmp.erase(tmp.begin() + i);
//                     tmpMin = findMin(G, tmp, restNum - 1);
//                 }
//                 else if (G[i][j] == '-') {
//                     tmp.erase(tmp.begin() + j);
//                     tmpMin = findMin(G, tmp, restNum - 1);
//                 }
//                 if (tmpMin < min) {
//                     min = tmpMin;
//                 }
//             }
//         }
//         return min;
//     }
// };

// int main() {
//     Solution solution;
//     vector<vector<char> > matrix1 = { {'0', '+', '-'}, {'-', '0', '+'}, {'+', '-', '0'} };
//     vector<vector<char> > matrix2 = { { '0', '0', '0' },{ '0', '0', '0' },{ '0', '0', '0' } };
//     int res = solution.minLeftMonsters(matrix1);
//     cout << res << endl;
//     return 0;
// }
class Solution {
public:
    int minLeftMonsters(vector<vector<char> > G) {
        int count = 0; // 最终的结果
        int sum = G.size();
        // 保存每一个强连通分量
        vector<vector<int> > sccs;
        KosarajuSCC(G, sccs);
        // 统计入度为0的SCC的个数
        for (int i = 0; i < sccs.size(); i++) {
            bool flag = true;
            for (int j = 0; j < sccs[i].size(); j++) {
                for (int k = 0; k < sum; k++) {
                    if (find(sccs[i].begin(), sccs[i].end(), k) != sccs[i].end()) {
                        continue;
                    }
                    // G[i][j]表示怪兽i和怪兽j互殴会发生的结果,
                    // ’-’代表怪兽i吃了怪兽j，j会消失
                    // 也说明有向图中存在从i到j的边
                    if (G[k][sccs[i][j]] == '-') {
                        flag = false;
                        break;
                    }
                }
                if (flag == false) {
                    break;
                }
            }
            if (flag) {
                count++;
            }
        }
        return count;
    }

    void KosarajuSCC(vector<vector<char> > G, vector<vector<int> >& sccs) {
        int sum = G.size();
        vector<bool> visited(sum, false);
        vector<vector<int> > graph(sum, vector<int>(sum, 0));
        vector<vector<int> > reverseGraph(sum, vector<int>(sum, 0));
        vector<int> reversePostOrder;
        vector<int> components;
        // 构建图的关系矩阵和逆矩阵GR
        for (int i = 0; i < sum; i++) {
            for (int j = 0; j < sum; j++) {
                // G[i][j]表示怪兽i和怪兽j互殴会发生的结果,
                // ’-’代表怪兽i吃了怪兽j，j会消失
                if (G[i][j] == '-') {
                    graph[i][j] = 1;
                }
                if (G[i][j] == '+') {
                    reverseGraph[i][j] = 1;
                }
            }
        }
        // 得到逆后序reversePostOrder
        // 先深度搜索，得到的reversePostOrder中的序列最后一个应当属于GR的源SCC，即GR的后序
        for (int i = 0; i < sum; i++) {
            if (!visited[i]) {
                dfs(i, reverseGraph, reversePostOrder, visited);
            }
        }
        // 上述reversePostOrder翻转一下才是真的逆后序，按dfs的post值从大到小排序
        // 第一个属于GR的源SCC
        reverse(reversePostOrder.begin(), reversePostOrder.end());

        // 第二次深度搜索，找出所有的强连通分量SCC
        // 此处的components相当于存储每一次SCC的所有元素
        visited.assign(sum, false);
        for (int i = 0; i < sum; i++) {
            components.clear();
            if (!visited[reversePostOrder[i]]) {
                dfs(reversePostOrder[i], graph, components, visited);
            }
            if(components.size() != 0) {
                sccs.push_back(components);
            }
        }
    }

    /*从节点v进行深读搜索*/
    void dfs(int v, vector<vector<int> > graph, vector<int>& order, vector<bool>& visited) {
        visited[v] = true;
        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i] && graph[v][i]) {
                dfs(i, graph, order, visited);
            }
        }
        order.push_back(v);
    }
};

int main() {
    Solution solution;
    vector<vector<char> > matrix1 = { { '0', '+', '-' },{ '-', '0', '+' },{ '+', '-', '0' } };
    vector<vector<char> > matrix2 = { { '0', '0', '0' },{ '0', '0', '0' },{ '0', '0', '0' } };
    vector<vector<char> > matrix3 = { { '0', '-', '-', '+', '0', '0' },
    { '+', '0', '0', '-', '0', '0' },
    { '+', '0', '0', '-', '-', '0' },
    { '-', '+', '+', '0', '0', '-' },
    { '0', '0', '+', '0', '0', '-' },
    { '0', '0', '0', '+', '+', '0' } };
    vector<vector<char> > matrix4 = { 
    { '0', '-', '+', '0', '0', '0', '0' },
    { '+', '0', '-', '0', '0', '0', '0' },
    { '-', '+', '0', '0', '0', '0', '-' },
    { '0', '0', '0', '0', '-', '+', '0' },
    { '0', '0', '0', '+', '0', '-', '0' },
    { '0', '0', '0', '-', '+', '0', '-' },
    { '0', '0', '+', '0', '0', '+', '0' } };
    int res = solution.minLeftMonsters(matrix3);
    cout << res << endl;
    system("pause");
    return 0;
}
