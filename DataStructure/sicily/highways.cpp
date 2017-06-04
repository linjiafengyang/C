#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
 
int dis[501][501];
struct Edge
{
    int a;
    int b;
    int w;
    Edge(int aa,int bb,int ww)
    {
        a = aa;
        b = bb;
        w = ww;
    }
};
 
bool cmp(Edge aa,Edge bb)
{
    return aa.w < bb.w;
}
 
int a[501];
 
//使用并查集实现kruskal算法
int find(int x)
{
    if(x == a[x])
        return x;
    else
    {
        a[x] = find(a[x]);
        return a[x];
    }
}
 
 
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        set<int> ss;
        vector<Edge> tt;
        int N;
        cin >> N;
        int i,j;
        for(i = 1;i <= N;i++)
        {
            for(j = 1;j <= N;j++)
            {
                cin >> dis[i][j];
                if(i > j)
                    tt.push_back(Edge(i,j,dis[i][j]));
            }
        }
        sort(tt.begin(),tt.end(),cmp);
        int max = 0;
        int num = 0;
        for(i = 1;i <= N;i++)
            a[i] = i;
        for(i = 0;i < tt.size();i++)
        {
            if(find(tt[i].a) != find(tt[i].b))
            {
                num++;
                max = tt[i].w;
                a[find(tt[i].a)] = a[find(tt[i].b)];
            }
            if(num == N-1)
                break;
        }
        cout << max << endl;
        if(T != 0)
            cout << endl;
    }
    return 0;
}                                 