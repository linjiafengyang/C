#include <stdio.h>
int main() {
	int count = 1;
	while(count <= 10) {
		printf("%s\n", count % 2 ? "****" : "++++++++");//求余，若为1，则为真，输出****；若为0，则为假，输出++++++++ 
		count++;
	}
	return 0;
}

