#include <stdio.h>
#define SIZE 20
int main() {
	int i,j;
	int a[SIZE]; 
	for(i = 0;i < SIZE;i++) {
		scanf("%d", &a[i]);
		for(j = 1;j < SIZE;j++) {
			if(a[i] == a[j]) {
				a[i] = a[j];
				printf("%d", a[i]);
			}
			else {
				printf("%d  %d", a[i], a[j]);
				a[i] = a[j];
			}
		}
	}
} 
