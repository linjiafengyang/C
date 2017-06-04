#include <iostream>
#include <cstdlib>
using namespace std;

void hanoi(int n, int start, int finish, int temp)
{
	if(n > 0)
	{
		hanoi(n - 1, start, temp, finish);
		cout << n << "from" << (char)start << "to" << (char)finish << endl;
		hanoi(n - 1, temp, finish, start);
	}
}

int main()
{
	int n;
	int start = 65, temp = 66, finish = 67;
	while(cin >> n)
	{
		hanoi(n, start, finish, temp);
	}
	return 0;
}