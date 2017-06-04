#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int len1, len2;
	while (cin >> len1) {
		int code[60001] = {0};
		int next[60001] = {0};
		for (int i = 1; i <= len1; i++) cin >> code[i];
		int index = 0;
		for (int i = 2; i <= len1; ++i)
		{
			index = code[index + 1] == code[i] ? index + 1 : 0;
			next[i] = index;
		}
		cin >> len2;
		index = 0;
		int test, result;
		for (int i = 1; i <= len2; ++i)
		{
			cin >> test;
			if (index != len1)
			{
				index = code[index + 1] == test ? index + 1 : next[index];
				if (index == len1)
				{
					result = i - len1;
				}
			}
		}
		index == len1 ? cout << result << endl : cout << "no solution" << endl;
	}
	return 0;
}