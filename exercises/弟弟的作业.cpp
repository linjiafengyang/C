#include <stdio.h>
int calculate(char s[]);
int main() {
	char s[10];
	int count = 0;
	while(gets(s)) {
		count += calculate(s);
	}
	printf("%d\n", count);
	return 0;
}
int calculate(char s[]) {
	char op;
	int i;
	int a = 0;
	int b = 0;
	int c = 0;
	int answer;
	for(i = 0; s[i] != '-' && s[i] != '+' && s[i]; i++) {
		if(s[i] >= '0' && s[i] <= '9') {//�����һ������ 
			a = a * 10 + s[i] - '0';
		}
	}
	op = s[i];//��¼+����- 
	for(i++; s[i] != '='; i++) {//����ڶ������� 
		b = b * 10 + s[i] - '0';
	}
	if(s[++i] == '?') {
		return 0;
	}
	else {
		for(; s[i]; i++) {//����ܵܵĴ� 
			c = c * 10 + s[i] - '0';
		}
	}
	switch(op) {
		case '+':
			answer = a + b;
			break;
		case '-':
			answer = a - b;
			break;
	}
	if(answer == c) {//��ȷ����ܵܵĴ𰸱Ƚ� 
		return 1;
	}
	else {
		return 0;
	}
}
