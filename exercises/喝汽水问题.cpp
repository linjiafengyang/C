#include <stdio.h>
int main() {
	int n;
	int m;
	int x;
	int temp;
	scanf("%d", &n);
	while(n) {
		temp = n;
		m = 0;
		while(temp >= 3) {
			x = temp / 3;//用3x个空瓶换回x瓶汽水 
			m = m + x;
			temp = temp - 2 * x;//空瓶数减少了2x个 
		}
		if(temp == 2) {//可以借一瓶汽水，再还3个空瓶，两清 
			m = m + 1;
		}
		printf("%d\n", m);
		scanf("%d", &n);
	}
}
