// Problem#: 19167
// Submission#: 4927383
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include "iostream"  
#include "cstring"  
#include "algorithm"  
#include "queue"  
#include "vector"  
using namespace std;  
int width[100001];//各个深度的广度  
int vis[100001];//记录遍历状态  
int level[100001];//记录入度  
int D,W;//记录深度与广度  
int flag;//标志位，为1则符合条件，为0不符合  
vector<int> a[10001];  
void dfs(int cur,int depth){  
    if(vis[cur]){//环  
        flag=0;  
        return;  
    }  
    vis[cur]=1;  
    width[depth]++;  
    if(D<depth){  
        D=depth;  
    }  
    if(W<width[depth]){  
        W=width[depth];  
    }  
      
    for (int i = 0; i < a[cur].size(); ++i)  
    {  
        int v = a[cur][i];  
//        if(!dfs(v,depth+1)){  
//            return false;  
//        }  
        if(!flag){  
            return;  
        }  
        dfs(v,depth+1);  
    }  
//    return true;  
}  
  
int main(){  
    int n,k;  
    int u,v;  
    while((cin>>n>>k)&& n){  
        D=0;W=0;  
        flag=1;  
        if(k>n){  
            flag=0;//如果边多于点必然不符合题意  
        }  
        memset(a, 0, sizeof(a));  
        memset(vis,0,sizeof(vis));  
        memset(width,0,sizeof(width));  
        memset(level,0,sizeof(level));  
        for(int i=0;i<k;i++){  
            cin>>u>>v;  
            a[u].push_back(v);  
            level[v]++;//设置入度  
        }  
        for (int i = 1; i <= n; ++i)  
        {  
            if(!level[i]){//当前入度为0的所有点遍历  
                dfs(i,0);  
            }  
        }  
        for(int i=1;i<=n;i++){  
            if(!vis[i]){//存在未遍历到的点  
                flag=0;  
            }  
        }  
        if(!flag){  
            cout<<"INVALID"<<endl;  
        }else{  
            cout<<D<<" "<<W<<endl;  
        }  
    }  
}                                 