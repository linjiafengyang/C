#include <stdio.h>
int main() {
	int n;
	int m;
	int x;
	int temp;
	scanf("%d", &n);
	while(n) {
		temp = n;
		m = 0;
		while(temp >= 3) {
			x = temp / 3;//��3x����ƿ����xƿ��ˮ 
			m = m + x;
			temp = temp - 2 * x;//��ƿ��������2x�� 
		}
		if(temp == 2) {//���Խ�һƿ��ˮ���ٻ�3����ƿ������ 
			m = m + 1;
		}
		printf("%d\n", m);
		scanf("%d", &n);
	}
}
