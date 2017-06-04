#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
	char s[10];
	while(scanf("%s", s) != EOF) {
		int a[10], b[10];
		int i, j, c;
		int len = strlen(s);
		for(i = 0; i < len; i++) {
			if(s[i] == '+' || s[i] == '-') {
				int first = 0;
				for(j = 0; j < i; j++) {
					a[j] = (s[j] - '0') * pow(10,i - j - 1); //注意：这里利用 s[j] - '0' 将字符型转化为整型 
					first = first + a[j];
				}
				c = len - i - 1; 
				int second = 0;
				for(j = 0; j < len - i - 1; j++) {
					b[j] = (s[j+i+1] - '0') * pow(10,c - 1);
					c--;
					second = second + b[j];	
				}
				if(s[i] == '+') {
					printf("%d\n", first+second);					
				}
				if(s[i] == '-') {
					printf("%d\n", first-second);
				}
			}
		}
	}
} 
/*输入1+1
      3-2
      50+50 
  输出2
  	  1
	  100*/ 
