#include <stdio.h>
#include <string.h>
int main() {
    int n, i, j, c, d, m;
    int k = 0;
    int len;
    char a[500][50], b[50];
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%s", b);
        for(j = 0; j < n; j++) {
            if(strcmp(b, a[j]) == 0) {
                break;
            }
        }
        if(j == n) {
            strcpy(a[k++], b);
        }
    }
    for(i = 1; i < k; i++) {
        for(m = 0; m < k - i; m++) {
            c = strlen(a[m]);
            d = strlen(a[m + 1]);
            len = c > d ? c : d;
            for(j = 0; j < len; j++) {
                if(a[m][j] > 90 && a[m + 1][j] > 90) {
                    if(a[m][j] > a[m + 1][j]) {
                        strcpy(b, a[m + 1]);
                        strcpy(a[m + 1], a[m]);
                        strcpy(a[m], b);
                        break;
                    }
                    else if(a[m][j] == a[m + 1][j]) {
                        continue;
                    }
                    else {
                        break;
                    }
                }
                else if(a[m][j] > 90 && a[m + 1][j] <= 90) {
                    if(a[m][j] > a[m + 1][j] + 32) {
                        strcpy(b, a[m + 1]);
                        strcpy(a[m + 1], a[m]);
                        strcpy(a[m], b);
                        break;
                    }
                    else if(a[m][j] == a[m + 1][j] + 32) {
                        continue;
                    }
                    else {
                        break;
                    }
                }
                else if(a[m][j] <= 90 && a[m + 1][j] > 90) {
                    if(a[m][j] + 32 > a[m + 1][j]) {
                        strcpy(b, a[m + 1]);
                        strcpy(a[m + 1], a[m]);
                        strcpy(a[m], b);
                        break;
                    }
                    else if(a[m][j] + 32 == a[m + 1][j]) {
                        continue;
                    }
                    else {
                        break;
                    }
                }
                else if(a[m][j] <= 90 && a[m + 1][j] <= 90) {
                    if(a[m][j] > a[m + 1][j]) {
                        strcpy(b, a[m + 1]);
                        strcpy(a[m + 1], a[m]);
                        strcpy(a[m], b);
                        break;
                    }
                    else if(a[m][j] == a[m + 1][j]) {
                        continue;
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
    for(m = 0; m < k; m++) {
        printf("%s\n", a[m]);
    } 
}
