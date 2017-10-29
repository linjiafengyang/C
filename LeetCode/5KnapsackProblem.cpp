/*
分组背包：
有N件物品和一个容量为V的背包. 第i件物品
的费用是c[i]，价值是w[i]. 这些物品被划分为若干
组，每组中的物品互相冲突，最多选一件. 
求解将哪些物品装入背包可使这些物品的费用总和不超
过背包容量，且价值总和最大
 */
#include <iostream>
using namespace std;
const int V = 1000;
const int T = 3;
const int K = 2;
int w[K][T] = {{5, 10, 8}, {15, 20, 15}};// 表示每一种物品的价值
int c[K][T] = {{200, 300, 400}, {400, 800, 200}};// 表示每一种物品的体积
int f[V + 1];

int max(int a, int b) {
    return a > b ? a : b;
}
int KP() {
    for (int i = 0; i <= V; i++) {
        f[i] = 0;
    }
    for (int k = 0; k < K; k++) {
        for (int v = V; v >= 0; v--) {// 将每一个分组当做一次01背包，故计算顺序为V递减
            for (int i = 0; i < T; i++) {// 针对每一个分组中的第一个i
                if (v - c[k][i] >= 0) {
                    f[v] = max(f[v], f[v - c[k][i]] + w[k][i]);
                }
            }
        }
    }
    return f[V];
}
int main() {
    cout << KP() << endl;
    return 0;
}