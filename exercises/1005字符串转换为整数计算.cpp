#include <stdio.h>
#include <string.h>
int main() {
	char infix[1000], op[1000];
	int num[1000];
	while(scanf("%s", infix) != EOF) {
		int len = strlen(infix);
		int h, i;
		for(i = 0; i < len; i++) {
			if(infix[i] == '-' && infix[i - 1] == '(') {
				for(h = len + 1; h > i; h--) {
					infix[h] = infix[h - 1];
				}
				infix[i] = '0';
				len++;
			}
		}
		int j = 0, k = 0;
		for(i = 0; i < len; i++) {
			if(infix[i] >= 48 && infix[i] <= 57) {  //ASCII码48表示数字0，57表示数字9 
				num[j++] = infix[i] - '0';//字符型转换为整型 
			}
			else if(infix[i] != '(' && infix[i] != ')') {
				op[k++] = infix[i];
			}
			else if(infix[i] == ')') {
				char c = op[k - 1];
				switch(c) {
					case '+':
						num[j - 2] = num[j - 2] + num[j - 1];
						break;
					case '-':
						num[j - 2] = num[j - 2] - num[j - 1];
						break;
					case '*':
						num[j - 2] = num[j - 2] * num[j - 1];
						break;
					case '/':
						num[j - 2] = num[j - 2] / num[j - 1];
						break;
				}
				j = j - 1;
				k = k - 1;
			}
		}
		printf("%d\n", num[0]);
	}
}
