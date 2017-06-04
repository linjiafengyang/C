#include <iostream>
using namespace std;
int factorial(int n);
int main(int argc, char const *argv[])
{
	int n;
	while (1) {
		cin >> n;
		if (n > -1)
		{
			cout << "..." << factorial(n) << endl;
		}
		else {
			break;
		}
	}
	return 0;
}
int factorial(int n) {
	if (n == 0)
	{
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}