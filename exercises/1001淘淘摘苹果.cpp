#include <stdio.h>
int main() {
	int a[10];
	int i, tall, counter;
	for(i = 0;i < 10;i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &tall);
	if(tall >= 100 && tall <= 120) {
		counter = 0;
		for(i = 0;i < 10;i++) {
			if(tall >= a[i] || (tall + 30) >= a[i]) {
				counter++;
			}	
		}	
	}
	printf("%d\n",counter);
	return 0;
} 
