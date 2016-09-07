#include <stdio.h>
int fun(int i, int k);
int main() {
	int i;
	int k, n;
	int j = 0;
	int bin[10];
	scanf("%d%d", &k, &n);
	while(n > 0) {//转成二进制数 
		bin[j++] = n % 2;
		n = n / 2;
	}
	int total = 0;
	for(i = 0; i < j; i++) {
		if(bin[i]) {
			total = total + fun(i, k);
		}
	}
	printf("%d\n", total);
	return 0;
}
int fun(int i, int k) {
	int temp = 1;
	int j;
	for(j = 0; j < i; j++) {
		temp = temp * k;
	}
	return temp;
}
/*给定一个正整数k(3≤k≤15),把所有k的方幂
及所有有限个互不相等的k的方幂之和
构成一个递增的序列，例如，当k=3时，这个序列是： 
1，3，4，9，10，12，13，… 
（该序列实际上就是：30，31，30+31，32，30+32，31+32，30+31+32，…） 

请你求出这个序列的第N项的值（用10进制数表示）。 
例如，对于k=3，N=100，正确答案应该是981。*/

