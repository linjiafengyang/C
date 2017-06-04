#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	string s1, s2;
	int re = 1;
	cin >> s1 >> s2;
	int size = s1.size();
	int temp = size - 1;
	for (int i = 1; i < size - 1; i++) {
		int j = s2.find(s1[i]);
		if (j == temp - 1) re *= 2;
		temp = j;
	}
	cout << re << endl;
	return 0;
}