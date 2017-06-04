#include <stdio.h>
char a[1000];
char * prefix(const char * const s1, const char * const s2);
int main() {
	const char s1[] = "distance";
	const char s2[] = "disjoint";
	printf("%s", prefix(s1, s2));
}
char * prefix(const char * const s1, const char * const s2) {
	int i = 0, j = 0;
	for(i = 0; i < 1000; i++) {
		a[i] = 0;
	}
	i = 0;
	while(s1[i] != '\0' && s2[i] != '\0') {
		if(s1[i] != s2[i]) {
			break;
		}
		else {
			a[j] = s1[i];
			j++;
		}
		i++;
	}
	if(i == 0) {
		return a;
	}
	return a;
}
