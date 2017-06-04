#include <stdio.h>
#include <string.h>
int main() {
	int n, i, j;
	int cntp = 0;
	int cntt = 0;
	char s[101];
	char *p1, *p2;
	scanf("%d", &n);
	for(i = 0; i < n && n < 10; i++) {
		scanf("%s", s);
		int cntp = 0;
		int cntt = 0;
		int cnta = 0;
		int ispat = 0;
		for(j = 0; s[j] != '\0'; j++) {
			if(s[j] == 'P') {
				cntp++;
			}
			else if(s[j] == 'T') {
				cntt++;
			}
			else if(s[j] == 'A') {
				cnta++;
			}
			else {
				cnta = 0;
			}
		}
		if(cntp == 1 && cntt == 1 && cnta != 0) {
			p1 = strchr(s, 'P');
			p2 = strchr(s, 'T');
			if((p1 - s) * (p2 - p1 - 1) == strlen(p2) - 1) {
				ispat = 1;
			}
		}
		if(ispat) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}
/*8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA*/
/*YES
YES
YES
YES
NO
NO
NO
NO*/
