#include <stdio.h>
int main() {
	int n, i, j;
	scanf("%d", &n);
	for(i = 0;i < n / 2 + 1;i++) {   //ѭ��ǰ��� n / 2 + 1 
		for(j = 0;j < i;j++) {       //��ӡ i �� ��- �� 
			printf("-"); 
		}
		for(j = 0;j < n - 2 * i;j++) {        //n - 2 * i ��ʾ��ӡ�ĸ����𽥼����� 
			printf("+");
		}
		for(j = 0;j < i;j++) {           //��ӡ i �� ��- �� 
			printf("-");
		}
		printf("\n");
	}
	for(i = 0;i < n / 2;i++) {		   // ѭ������� n / 2 �� 
		for(j = 0;j < n / 2 - i - 1;j++) {      //��ӡ�� ��- ���𽥼��� 
			printf("-");
		}
		for(j = 0;j < 2 * i + 3;j++) {           //i = 0ʱ��ӡ 3 ����i = 1ʱ��ӡ 5 �������ε���  
			printf("+");
		}
		for(j = 0;j < n / 2 - i - 1;j++) {
			printf("-");
		} 
		printf("\n");
	}
	return 0;
}
	
