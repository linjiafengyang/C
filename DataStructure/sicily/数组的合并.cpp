#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int a[5], b[5], c[10];
	for (int i = 0; i < 5; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 5; ++i)
	{
		cin >> b[i];
	}
	int m = 0;
	int n = 0;
	int temp = 0;
	while (m < 5 && n < 5) {
		if (a[m] <= b[n])
		{
			c[temp++] = a[m++];
		}
		else {
			c[temp++] = b[n++];
		}
	}
	while (m < 5) {
		c[temp++] = a[m++];
	}
	while (n < 5) {
		c[temp++] = b[n++];
	}
	for (int i = 0; i < 10; ++i)
	{
		cout << c[i] << " ";
	}
	return 0;
}