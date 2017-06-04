#include<stdio.h>
long long a[100000], b[100000][3];
int main() {
	int n, m, i;
	scanf("%d%d", &n, &m);
	long long add = 0, opp = 1, sum[n], mult = 1;
	for (i = 0; i <= n - 1; i++) {
		scanf("%lld", &a[i]);
		if (i == 0) {
			sum[0] = a[0];
		}
		else {
			sum[i] = sum[i - 1] + a[i];
		}
	}
    for (i = 0; i <= m - 1;i++) {
		scanf("%lld",&b[i][0]) ;
		if (b[i][0] == 1) {
			opp = -opp;
			mult = -mult;
		}
		else if (b[i][0] == 2) {
			scanf("%lld", &b[i][1]);
			if (i == 0) {
				add = b[i][1];
		    }  
		    else {
			    add = add + mult*b[i][1];
		    } 
	    }
		else if (b[i][0] == 3){
			scanf("%lld%lld", &b[i][1], &b[i][2]);
			if(b[i][1] == 1) {
				printf("%lld\n",opp*(sum[b[i][2] - 1] + add* b[i][2]));
			} 
			else {
				printf("%lld\n",opp*(sum[b[i][2]-1]  + add*(b[i][2] + 1)- sum[b[i][1] - 2] -add*b[i][1]));
			}
		}
	}
} 
/*5 5
1 2 3 4 5
3 1 1
1
3 1 3
2 5
3 4 5 */
