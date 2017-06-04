#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	char mark;
	cin >> n >> mark;
	int mark_to_number;
	int index;
	int no_used_number;
	for (int i = 1; i <= 23; i++) {
		mark_to_number = 2 * i * i - 1;
		if (n == mark_to_number) {
			index = i;
			no_used_number = 0;
			break;
		}
		else if (n < mark_to_number) {
			index = i - 1;
			no_used_number = n - 2 * (i - 1) * (i - 1) + 1;
			break;
		}
	}
	for (int i = 2 * index - 1; i > 1; i = i - 2) {
		int blank_number = index - (i + 1) / 2;
		for (int k = 0; k < blank_number; k++) {
			cout << ' ';
		}
		for (int j = 0; j < i; j++) {
			cout << mark;
		}
		cout << endl;
	}
	for (int i = 0; i < index - 1; i++) {
		cout << ' ';
	}
	cout << mark << endl;
	for (int i = 3; i <= 2 * index - 1; i = i + 2) {
		int blank_number = index - (i + 1) / 2;
		for (int k = 0; k < blank_number; k++) {
			cout << ' ';
		}
		for (int j = 0; j < i; j++) {
			cout << mark;
		}
		cout << endl;
	}
	cout << no_used_number << endl;
}
/*
所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。

给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

输入格式：

输入在一行给出1个正整数N（<=1000）和一个符号，中间以空格分隔。

输出格式：

首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。

输入样例：
19 *
输出样例：
*****
 ***
  *
 ***
*****
2
*/