#include <stdio.h> 
int main() {
	int t, n, i, j;
	int max, secondmax;
	int a[10010];
	max = a[0];
	scanf("%d", &t);
	for(i = 0;i < t;i++) {
		scanf("%d", &n);
		if(n >= 2 && n <= 10000){
			for(j = 0;j < n;j++) {
				scanf("%d", &a[j]);
				if(a[j] >= max) {
					secondmax = max;
					max = a[j];
					if(max == secondmax) {
						max = secondmax; 
						secondmax = a[j];
					} 
				}
			}
			printf("%d\n", secondmax);
		}
	}
	return 0;
}
