#include <stdio.h>
int main() {
	int a, b, t, r;
	printf("�������������֣�\n");
	scanf("%d%d", &a, &b);
	if(a < b) {
		t = b;
		b = a;
		a = t;
	}
	int n = a * b;
	r = a % b;
	while(r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	printf("���Լ����%d����С��������%d\n", b, n / b);
	return 0;
}
