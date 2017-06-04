#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	while ((cin >> s) != "XXX") {
		char pre;
		int count = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] >= '0' && s[i] <= '9') count = count * 10 + s[i] - '0';
			else {
				if (count > 0) {
					for (int j = 0; j < count - 1; j++) cout << pre;
					count = 0;
				}
				pre = s[i];
				cout << s[i];
			}
		}
		if (count > 0)
		{
			for (int i = 0; i < count - 1; ++i)
			{
				cout << pre;
			}
		}
		cout << endl;
	}
	return 0;
}