#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(string a, string b) {
	return a.size() > b.size();
}
bool ismatch(string a, string b) {
	int len = a.size();
	for (int i = 0; i < len; ++i)
	{
		if (a[i] == 'A' && b[i] != 'T') return false;
		if (a[i] == 'T' && b[i] != 'A') return false;
		if (a[i] == 'C' && b[i] != 'G') return false;
		if (a[i] == 'G' && b[i] != 'C') return false;
	}
	return true;
}
int main(int argc, char const *argv[])
{
	int t, n;
	string str[101];
	int len[101];
	bool used[101];
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> str[i];
		sort(str, str + n, cmp);
		for (int i = 0; i < n; ++i)
		{
			len[i] = str[i].size();
			used[i] = false;
		}
		int count = 0;
		for (int i = 0; i < n; ++i)
		{
			if (!used[i])
			{
				for (int j = i + 1; j < n && len[j] == len[i]; ++j)
				{
					if (ismatch(str[i], str[j]) && !used[j])
					{
						count++;
						used[i] = used[j] = true;
						break;
					}
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}