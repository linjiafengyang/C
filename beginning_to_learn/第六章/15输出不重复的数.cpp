#include <stdio.h>
#define SIZE 20
int main() {
	int a[20] = {0};//�����ʼ���Ǳ���ģ��������ִ��� 
	int i, j;
	int k = 0;
	int duplicate;
	int value;
	for(i = 0; i < SIZE; i++) {
		duplicate = 0; 
		scanf("%d", &value);
		for(j = 0; j < k; j++) {
			if(a[j] == value) {
				duplicate = 1;
				break;
			}
		}
		if(!duplicate) {
			a[k++] = value;
		}
	}
	for(i = 0; a[i] != 0; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
