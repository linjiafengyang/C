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
			cout << "..." << fibonacci(n) << endl;
		}
		else {
			break;
		}
	}
	return 0;
}
int fibonacci(int n) {
	if (n <= 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else {
		return fibonacci(n - 2) + fibonacci(n - 1);
	}
}