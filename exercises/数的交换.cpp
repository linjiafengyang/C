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
	min = a;//ʹmax��min��ָ��a[0]
	for(p = a + 1; p < a + 10; p++) {
		if(*p > *max) {//��������ַ����max  
			max = p;
		}
		else if(*p < *min) {//��С����ַ����min
			min = p;
		}
	}
	temp = a[0];//����С�����һ�������� 
	a[0] = *min;
	*min = temp;
	if(max == a) {//�����һ�����պ������������ʹmaxָ��������
		max = min;
	}
	temp = a[9];//������������һ�������� 
	a[9] = *max;
	*max = temp;
}
void output(int *a) {
	int *p;
	for(p = a; p < a + 10; p++) {
		printf("%d ", *p);
	}
}
