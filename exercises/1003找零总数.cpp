#include <stdio.h>
int money[] = {500, 200, 100, 50, 10, 5};
int sum = 1;
void count(int flag, int left) {
	int i;
	for(i = flag; i < 6; i++) {
		if((left - money[i] < money[i]) && (left - money[i] >= 0)) {
			sum++;
			count(i + 1, left - money[i]);
		}
		else {
			if(left - money[i] >= money[i]) {
				sum++;
				count(i, left - money[i]);
			}
		}
	}
}
int main() {
	float input;
	while(scanf("%f", &input) != EOF) {
		sum = 1;
		count(0, (int)(input * 10));
		printf("%d\n", sum);
	}
}
