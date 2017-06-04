#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	int first, n, k, temp, i, j, l;
	int data[100005];
	int next[100005];
	int list[100005];
	int final[100005];
	scanf("%d %d %d", &first, &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &temp);
		scanf("%d %d", &data[temp], &next[temp]);
	}
	l = 0;
	while (first != -1) {
		list[l] = first;
		l++;
		first = next[first];
	}
	for (i = 0; i < l; i++) {
		final[i] = list[i];
	}
	for (i = 0; i < (l - l % k); i++) {
		final[i] = list[(i / k) * k + k - i % k - 1];
	}
	for (i = 0; i < l - 1; i++) {
		printf("%05d %d %05d\n", final[i], data[final[i]], final[i + 1]);
	}
	printf("%05d %d %d\n", final[l - 1], data[final[l - 1]], -1);
	system("pause");
	return 0;
}
/*
给定一个常数K以及一个单链表L，请编写程序将L中每K个结点反转。例如：给定L为1→2→3→4→5→6，K为3，则输出应该为3→2→1→6→5→4；如果K为4，则输出应该为4→3→2→1→5→6，即最后不到K个元素不反转。

输入格式：

每个输入包含1个测试用例。每个测试用例第1行给出第1个结点的地址、结点总个数正整数N(<= 105)、以及正整数K(<=N)，即要求反转的子链结点的个数。结点的地址是5位非负整数，NULL地址用-1表示。

接下来有N行，每行格式为：

Address Data Next

其中Address是结点地址，Data是该结点保存的整数数据，Next是下一结点的地址。

输出格式：

对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。

输入样例：
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
输出样例：
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/