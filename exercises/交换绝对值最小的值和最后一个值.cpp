#include <stdio.h>
#include <math.h>
int main(){
	int i, j, temp = 0;
	int a[10];
	for(i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	int smallest = fabs(a[0]);
	for(i = 0; i < 10; i++) {
		if(smallest > fabs(a[i])) {
			smallest = fabs(a[i]);
			temp = i;
		}
	}
	j = a[temp];
	a[temp] = a[9];
	a[9] = j;
	for(i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
}
