// Problem#: 18003
// Submission#: 4655159
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int f[110][51];

void init(int idx, int num)//初始化 m 个月前兔子的总数
{
     for (int i = 50; num != 0 && i >= 0; i --)
     {
         f[idx][i] = num % 10;
         num /= 10;
     }
}

void addition(int idx, int m)//高精度加法
{
     int temp;
     
     for (int i = 50; i >= 1; i --)
     {
         temp = f[idx][i];
         f[idx][i] = (temp + f[idx - 1][i] + f[idx - m][i]) % 10;            //注意是先加再模
         f[idx][i - 1] = (temp + f[idx - 1][i] + f[idx - m][i]) / 10;        //注意是先加再除
     }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int m, d, c;
    
    while (scanf("%d%d", &m, &d), m > 0 && d > 0)
    {
          memset(f, 0, sizeof(f));
          for (int i = 0; i <= d; i ++)
          {
              if (i <= m)
              init(i, i + 1);//初始化 m 个月前兔子的总数
              else
              addition(i, m);//递推兔子的总数
          }
          
          for (int i = 0; i <= 50; i ++)//去掉结果开头的 0 。
          {
              if (f[d][i] != 0)
              {
                  c = i;
                  break;
              }
          }
          
          for (int i = c; i <= 50; i ++)
          printf("%d", f[d][i]);
          printf("\n");
    }
    return 0;
}
