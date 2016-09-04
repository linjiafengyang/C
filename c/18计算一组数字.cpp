#include <stdio.h>
int main() {
	int s = 0;
	int a, n, t;
	printf("ÇëÊäÈëaºÍn£º\n");
	scanf("%d%d", &a, &n);
	t = a;
	while(n > 0) {
		s += t;
		a = a * 10;
		t += a;
		n--;
	}
	printf("a+aa+...=%d\n", s);
	return 0;
}
