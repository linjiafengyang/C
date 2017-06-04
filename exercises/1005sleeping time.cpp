#include <stdio.h>
int main() {
	int a, b, c, d, e, f;
	char i;
	scanf("%d:%d", &a, &b);  // a 表示入睡时间的钟点，b 表示分钟，下面 c d 相同  
	scanf("%d:%d", &c, &d);
	if(d >= b) {              //起床时的分钟 d 比 入睡时的分钟 b 大 
		f = d - b;            //求出两个分钟之间的间隔 f 
		if(a < c) {           //入睡时的钟点 a 比 起床时的钟点 c 小 
			e = c - a;         //求出两个钟点之间的间隔 e 
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
		printf("%d:%02d", e, f);  //%02d 输出为0：05的样式 
	}
	return 0;
}
