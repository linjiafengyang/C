#include <stdio.h>
int main() {
	int count = 1;
	while(count <= 10) {
		printf("%s\n", count % 2 ? "****" : "++++++++");//���࣬��Ϊ1����Ϊ�棬���****����Ϊ0����Ϊ�٣����++++++++ 
		count++;
	}
	return 0;
}

