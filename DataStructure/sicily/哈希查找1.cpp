#include <iostream>
#include <string.h>
using namespace std;
int a[10001];
void my_hash(int value, int m) {
	int temp = value % m;
	while (a[temp] != -1) temp = (temp + 1) % m;
	a[temp] = value;
}
int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	memset(a, -1, sizeof a);
	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;
		my_hash(value, m);
	}
	for (int i = 0; i < m; i++) {
		cout << i << "#";
		if (a[i] != -1) cout << a[i] << endl;
		else cout << "NULL" << endl;
	}
	return 0;
}