#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	char s1[5], s2[5];
	int i, j, k;
	for(i = 0; i < n; i++) {
		scanf("%s%s", s1, s2);
		int count1 = 0;
		int count2 = 0;	
		for(j = 0; j < 4; j++) {
			if(s1[j] == s2[j]) {
				count1++;
			}
		}
		for(j = 0; j < 4; j++) {
			for(k = 0; k < 4; k++) {
				if(k == j) {
					continue;
				}
				else if(s1[j] == s2[k]) {
					count2++;
				}
			}
		}
		printf("%dA%dB\n", count1, count2);
	}
}
//2
//5204 4902
//0123 3210
//shuchu:
//1A2B
//0A4B
