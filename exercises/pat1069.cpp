/*
分析：用mapp存储当前用户有没有已经中奖过～当输入的时候，
判断当前字符串是否已经在mapp中出现过，如果出现过就将s+1。
每次判断i是否等于s，如果等于s且当前用户没有中过奖，
就将它的名字输出，并且s = s + n～并将mapp[str]标记为1，
且flag标记为true表示有过人中奖。最后flag如果依然是false说明要输出Keep going…
 */
#include <iostream>
#include <map>
using namespace std;
int main() {
	int m, n, s;
	cin >> m >> n >> s;
	string str;
	map<string, int> mapp;
	bool flag = false;
	for (int i = 1; i <= m; i++) {
		cin >> str;
		if (mapp[str] == 1) s = s + 1;
		if (i == s && mapp[str] == 0) {
			mapp[str] = 1;
			cout << str << endl;
			flag = true;
			s = s + n;
		}
	}
	if (flag == false) cout << "Keep going...";
	return 0;
}