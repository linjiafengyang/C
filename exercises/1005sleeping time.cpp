#include <stdio.h>
int main() {
	int a, b, c, d, e, f;
	char i;
	scanf("%d:%d", &a, &b);  // a ��ʾ��˯ʱ����ӵ㣬b ��ʾ���ӣ����� c d ��ͬ  
	scanf("%d:%d", &c, &d);
	if(d >= b) {              //��ʱ�ķ��� d �� ��˯ʱ�ķ��� b �� 
		f = d - b;            //�����������֮��ļ�� f 
		if(a < c) {           //��˯ʱ���ӵ� a �� ��ʱ���ӵ� c С 
			e = c - a;         //��������ӵ�֮��ļ�� e 
		}
		if(a > c) {
			e = c + 24 - a;     
		}
		printf("%d:%d", e, f);
	}
	if(d < b) {
		f = d + 60 - b;
		if(a < c) {
			e = c - 1 - a;
		}
		if(a > c) {
			e = c + 23 - a;
		}
		printf("%d:%02d", e, f);  //%02d ���Ϊ0��05����ʽ 
	}
	return 0;
}
