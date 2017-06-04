#include <stdio.h>
void input(int *a);
void max_min_value(int *a);
void output(int *a);
int main() {
	int a[10];
	input(a);
	max_min_value(a);
	output(a);
	return 0;
}
void input(int *a) {
	int i;
	for(i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
}
void max_min_value(int *a) {
	int *max, *min, *p, temp;
	max = a;
	min = a;//使max和min都指向a[0]
	for(p = a + 1; p < a + 10; p++) {
		if(*p > *max) {//将大数地址赋给max  
			max = p;
		}
		else if(*p < *min) {//将小数地址赋给min
			min = p;
		}
	}
	temp = a[0];//将最小数与第一个数互换 
	a[0] = *min;
	*min = temp;
	if(max == a) {//如果第一个数刚好是最大数，则使max指向该最大数
		max = min;
	}
	temp = a[9];//将最大数与最后一个数交换 
	a[9] = *max;
	*max = temp;
}
void output(int *a) {
	int *p;
	for(p = a; p < a + 10; p++) {
		printf("%d ", *p);
	}
}
