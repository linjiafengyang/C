#include <stdio.h>
int fun(int i, int k);
int main() {
	int i;
	int k, n;
	int j = 0;
	int bin[10];
	scanf("%d%d", &k, &n);
	while(n > 0) {//ת�ɶ������� 
		bin[j++] = n % 2;
		n = n / 2;
	}
	int total = 0;
	for(i = 0; i < j; i++) {
		if(bin[i]) {
			total = total + fun(i, k);
		}
	}
	printf("%d\n", total);
	return 0;
}
int fun(int i, int k) {
	int temp = 1;
	int j;
	for(j = 0; j < i; j++) {
		temp = temp * k;
	}
	return temp;
}
/*����һ��������k(3��k��15),������k�ķ���
���������޸�������ȵ�k�ķ���֮��
����һ�����������У����磬��k=3ʱ����������ǣ� 
1��3��4��9��10��12��13���� 
��������ʵ���Ͼ��ǣ�30��31��30+31��32��30+32��31+32��30+31+32������ 

�������������еĵ�N���ֵ����10��������ʾ���� 
���磬����k=3��N=100����ȷ��Ӧ����981��*/

