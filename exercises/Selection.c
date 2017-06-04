#include <stdio.h>
int main() {
	int num[10000];
	int m[20];
	int n, min;
	int i, j, k, temp;
	scanf("%d", &n);
	for(k = 0; k < n; k++) {
		scanf("%d", &m[k]);
		for(i = 0; i < m[k]; i++) {
			scanf("%d", &num[i]);
		}
    	for(i = 0; i < m[k]; i++) {
    		min = num[i];
    		for(j = i + 1; j < m[k]; j++) {
    			if(min > num[j]) {
    				temp = num[j];
    				num[j] = num[i];
    				num[i] = temp;
    			}
    		}
		}
		for(i = 0; i < m[k] - 1; i++) {
    		printf("%d ", num[i]);
		}
  		printf("%d\n", num[i]);
	}
	return 0;
}
