#include <stdio.h>
int main(){
	int m, n;
	int temp1;
	int temp2;
	int r;
	scanf("%d%d", &m, &n);
	temp1 = m;
	temp2 = n;
	while(n != 0) {
		r = m % n;
		m = n;
		n = r;
	}
	printf("%d %d", m, temp1 * temp2 / m);
	return 0;
}
