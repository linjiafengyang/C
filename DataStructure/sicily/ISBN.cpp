#include <iostream>
#include <string>
#include <sstream>
using namespace std;
struct Node
{
	int num[50];
	int weight[50];
};
int main(int argc, char const *argv[])
{
	string s;
	while (cin >> s) {
		Node n;
		int num = 10;
		int len = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				n.num[len] = s[i] - 48;
				n.weight[len++] = num--;
			}
		}
		int sum = 0;
		for (int i = 0; i < len; ++i)
		{
			sum += n.num[i] * n.weight[i];
		}
		int add = sum % 11 == 0 ? 0 : 11 - sum % 11;
		string addtos1 = "";
		if (add != 10)
		{
			stringstream ss;//char c = add + 48;
			ss << add;//addtos1 += c;
			ss >> addtos1;//is ok.
		}
		else {
			addtos1 += "X";
		}
		string s1 = s;
		s1 += '-';
		s1 += addtos1;
		cout << s1 << endl;
	}
	return 0;
}