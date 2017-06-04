#include <iostream>
#include <stack>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	double item;
	stack<double> numbers;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> item;
		numbers.push(item);
	}
	while(!numbers.empty()) {
	    cout << numbers.top() << " ";
	    numbers.pop();
	}
	return 0;
}