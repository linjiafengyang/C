#include <stdio.h>
#include <stdlib.h>
typedef struct People
{
	char name[6];
	int y;
	int m;
	int d;
} People;
int cmp(void const *p1, void const *p2) {
	if (((People *)(p1))->y > ((People *)(p2))->y) return 1;
	else if (((People *)(p1))->y < ((People *)(p2))->y) return 0;
	else {
		if (((People *)(p1))->m > ((People *)(p2))->m) return 1;
		else if (((People *)(p1))->m < ((People *)(p2))->m) return 0;
		else {
			if (((People *)(p1))->d > ((People *)(p2))->d) return 1;
			else if (((People *)(p1))->d < ((People *)(p2))->d) return 0;
			else return 1;
		}
	}
}
int cmp1(People p1, People p2) {
	if (p1.y > p2.y) return 1;
	else if (p1.y == p2.y) {
		if (p1.m > p2.m) return 1;
		else if (p1.m == p2.m && p1.d > p2.d) return 1;
		else return 0;
	}
	else return 0;
}
int main() {
	int n, i;
	People *a;
	People p1, p2;
	p1.y = 1814;
	p1.m = 9;
	p1.d = 6;
	p2.y = 2014;
	p2.m = 9;
	p2.d = 6;
	scanf("%d", &n);
	//while (scanf("%d", &n) != 0) {
		a = (People *)malloc(n * sizeof(People));
		i = 0;
		while (i < n) {
			scanf("%s%d/%d/%d", &a[i].name, &a[i].y, &a[i].m, &a[i].d);
			if (cmp1(a[i], p2) || cmp1(p1, a[i])) {
				n--;
			}
			else {
				i++;
			}
		}
		qsort(a, n, sizeof(People), cmp);
		if (n > 0) printf("%d %s %s\n", n, a[0].name, a[n-1].name);
		else printf("0\n");
		free(a);
	//}
	return 0;
}