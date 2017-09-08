/*
韩信点兵：3人一排，5人一排，7人一排，看最后一排的人数可知总人数
 */
#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	bool flag = false;
	for (int i = 11; i < 100; i++) {
		if (i % 3 == a && i % 5 == b && i % 7 == c) {
			cout << i << endl;
			flag = true;
			break;
		}
	}
	if (!flag) {
		cout << "No answer" << endl;
	}
	return 0;
}