#include <stdio.h>
int main() {
	int a, b;
	int counter = 0;
	scanf("%d", &a);
	while(counter < a-1) {
		scanf("%d", &b);
		if(b > 0) {
			printf("%d ", b);	
		}
		counter = counter+1;
	}
	while(counter < a) {
		scanf("%d", &b);
		if(b > 0) {
			printf("%d", b);/*�����ո�*/ 
		}
		else {
			printf("\b");/*��֤�����һ�����϶������ո���Ϊ������һ���������㣬��ǰ�治�����ո���С���㣬ֱ��ȥ��ǰ���������µĿո�*/ 
		}
		counter = counter+1;
	}
	printf("\n");
	return 0;
}
