#include <cstdio>;
const int maxn = 500000 + 10;
int left[maxn], right[maxn];
void take(int x) {
    right[left[x]] = right[x];
    left[right[x]] = left[x];
}
void link(int x, int y) {
    right[x] = y;
    left[y] = x;
}
int main() {
    int cases, n, m, j, i;
    int type, x, y;
    scanf("%d", &cases);
    for(i = 0; i < cases; i++) {
        scanf("%d%d", &n, &m);
        for(j = 1; j <= n; j++) {
            right[j] = j + 1;
            left[j] = j - 1;    
        }
        right[0] = 1;
        left[n + 1] = n;
        for(j = 0; j < m; j++) {
            scanf("%d%d%d", &type, &x, &y);
            switch(type) {
                case 1:
                    take(x);
                    link(left[y], x);
                    link(x, y);
                    break;
                case 2:
                    take(x);
                    link(x, right[y]);
                    link(y, x);
                    break;
            }
        }
        int start;
        for(j = 0, start = 0; j < n; j++) {
            printf("%d ", right[start]);
            start = right[start];
        }
        printf("\n");
    }
    return 0;
}
