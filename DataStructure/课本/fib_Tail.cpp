#include <iostream>
using namespace std;
int fibonacci(int n);
int main(int argc, char const *argv[])
{
	int n;
	while (1) {
		cin >> n;
		if (n > -1)
		{
			cout << "..." << fibonacci(n + 1) << endl;
		}
		else {
			break;
		}
	}
	return 0;
}
int fibonacci(int n) {
	int last_but_one;
	int last_value;
	int current;
	if (n <= 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else {
		last_but_one = 0;
		last_value = 1;
		for (int i = 2; i <= n; ++i)
		{
			current = last_but_one + last_value;
			last_but_one = last_value;
			last_value = current;
		}
		return current;
	}
}