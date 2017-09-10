/*
周期串问题，例如abcabcabc最小周期串为3，hohoho最小周期为2
 */
#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int len = s.length();
	int i;//i记录周期长度,j记录从第二个周期开始字符的位置
	for (i = 1; i <= len; i++) {
		if (len % i == 0) { //字符串的长度一定可以被周期整除
			int flag = 1;
			//检测 字符串是否具有周期性
			for (int j = i; j < len; j++) {
				if (s[j] != s[j % i]) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				cout << i;
				break;
			}
		}
	}
	return 0;
}