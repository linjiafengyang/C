#include <stdio.h>
#include <time.h>
int main() {
	time_t start, end;
	long int i;
	start = time(NULL);
	for(i = 0; i < 10000000; i++) {
		;
	}
	end = time(NULL);
	printf("ʱ����Ϊ%6.3f\n", difftime(end, start));
}
