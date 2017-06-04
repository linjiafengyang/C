#include <stdio.h>
int main() {
	int num[10000];
	int m[20];
	int n;
	int i, j, k, temp;
    scanf("%d", &n);
    for (j = 0; j < n; j++) {
    	scanf("%d", &m[j]);
    	for(i = 0; i < m[j]; i++) {
    	  	scanf("%d", &num[i]);
		}
		for(i = 1; i < m[j]; i++) {
			temp = num[i];
    		for(k = i - 1; k > -1 && num[k] > temp; k--) {
    			num[k+1] = num[k];
				num[k] = temp;
			}
		}
  		for(i = 0; i < m[j]; i++) {
			printf("%d ", num[i]);
		}
		printf("\n");
	}
    return 0;
}
