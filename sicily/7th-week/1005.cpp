#include <stdio.h>
long long a[10000000];
int main(){
    int n, m, i, x, y, z;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++ ) {
        scanf("%d%d%d", &x, &y, &z);
        a[40001 * x + 200 * y + z] = 1;
    }
    for (i = 0; i < m; i++ ) {
        scanf("%d%d%d",&x,&y,&z);
        if (a[40001 * x + 200 * y + z] == 1) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
}
