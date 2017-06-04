#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int N, school, grade;
	scanf("%d", &N);
	int *s = new int[N];
	memset(s, 0, N * sizeof(int));
	int num = 0;
	int high = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &school, &grade);
		s[school] += grade;
		if (s[school] > high) {
			num = school;
			high = s[school];
		}
	}
	printf("%d %d\n", num, high);
	return 0;
}