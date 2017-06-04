#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int test;
	int num;
	int array[100];
	int count = 0;
	cin >> test;
	while (test--) {
		cin >> num;
		count = 0;
		for (int i = 0; i < num; i++) cin >> array[i];
		for (int i = 0; i < num; ++i)
		{
			for (int j = 0; j < num; ++j)
			{
				if (array[j] == array[i] * 2 && array[j] != 0) count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}