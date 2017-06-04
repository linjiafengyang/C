#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	string s1, s2;
	cin >> s1 >> s2;
	int count = 0;
	for (int i = 0; i + 1 < s1.size(); i++) {
		for (int j = 0; j + 1 < s2.size(); j++) {
			if (s1[i] == s2[j + 1] && s1[i + 1] == s2[j]) {
				count++;
				break;
			}
		}
	}
	cout << (int)pow(2.0, 1.0 * count);
	return 0;
}