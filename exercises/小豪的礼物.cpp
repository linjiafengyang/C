#include <stdio.h> 
#include <math.h>
main () {
	int n, b[100];
	int i, j, h;
	char a[101][100];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		if (b[i] == 1) {
			scanf("%s", &a[i]);
		}
		else {
			scanf("%s", &a[i]);
			printf("%s ", a[i]);
			for (j = i - 1; j >= 0; j--) {
				if (b[j] == 1) {
					printf("%s\n", a[j]);
					b[j] = 0;
					break;
				}
			}
		}
	}
}
/*
 ‰»Î
8
1 OneMillionCheck
1 TomorrowStar
1 IBoom5s
2 Tey
2 Mmmmm
1 Excalibur
2 Joh
2 Lily
 ‰≥ˆ
Tey IBoom5s
Mmmmm TomorrowStar
Joh Excalibur
Lily OneMillionCheck*/ 
