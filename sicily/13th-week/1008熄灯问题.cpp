#include <stdio.h>
int main() {
	int light_num;
	int temp;
	scanf("%d%d", &light_num, &temp);
	int i, j;
	int k = 0, n = 0;//kΪ�Ǻţ������ﵽtemp��ֵʱ��Ϩ��� 
	int light[1000] = {0};
	for(i = 0; n < light_num; i++) {
		if(i == light_num) {
			i = 0;//���ǵ�һ��ѭ�����i����Ϊ0 
		}
		if(light[i] == 0) {//�����ţ�Ϩ��ĵƲ����� 
			k++;
		}
		if(k == temp) {
			k = 0;//k����Ϊ0 
			n++;//��¼�Ѿ�Ϩ��ĵƵ����� 
			light[i] = 1;//��Ϩ�� 
			printf("%d\n", i + 1);
		}
	}
	return 0;
}
//����13 5
//���5 10 2 8 1 9 4 13 12 3 7 11 6 
