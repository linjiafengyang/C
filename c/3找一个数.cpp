#include <stdio.h>
#include <math.h>
int main() {
	long int i, x, y;
	for(i = 0; i < 100000; i++) {
		x = sqrt(i + 100);
		y = sqrt(i + 268);
		if(x * x == i + 100 && y * y == i + 268) {
			printf("%ld\n", i);
		}
	}
	return 0;
}
/*һ��������������100����һ��
��ȫƽ�������ټ���168����һ����ȫƽ������
���ʸ����Ƕ��٣�*/
