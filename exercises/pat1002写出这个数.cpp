#include <stdio.h>
int main() {
	char s[110];
	scanf("%s", s);
	int i;
	int sum = 0;
	for(i = 0; s[i] != '\0'; i++) {//����ÿһ������ 
		sum = sum + s[i] - '0';//����� 
	}
	int mask = 1;
	int temp = sum;
	while(temp > 9) {
		temp /= 10;
		mask *= 10;//����sum��λ����ǧλ���ǣ� 
	}
	while(mask > 0) {
		int d = sum / mask;//ÿһλ�ϵ����� 
		switch(d) {
			case 0:
				printf("ling");
				break;
			case 1:
				printf("yi");
				break;
			case 2:
				printf("er");
				break;
			case 3:
				printf("san");
				break;
			case 4:
				printf("si");
				break;
			case 5:
				printf("wu");
				break;
			case 6:
				printf("liu");
				break;
			case 7:
				printf("qi");
				break;
			case 8:
				printf("ba");
				break;
			case 9:
				printf("jiu");
				break;
		}
		if(mask > 9) {//��֤���һ��ƴ������û�пո� 
			printf(" ");
		}
		sum %= mask;//�õ����� 
		mask /= 10;//λ����һ 
	}
}
