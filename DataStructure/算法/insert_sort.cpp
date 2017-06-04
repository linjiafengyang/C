#include <iostream>
using namespace std;

void insert_sort( int a[], int n )
{
	for( int i = 1; i < n; i++ )
	{
		int tmp = a[i];
		int index = i - 1;
		while( tmp < a[index] && index >= 0 )
		{
			a[index + 1] = a[index--];
		}
		a[index + 1] = tmp;
	}
}
void insertion_sort(int a[], int first, int last) {
	for (int i = first + 1; i <= last; i++) {
		int tmp = a[i];
		int index = i - 1;
		while (tmp < a[index] && index >= first) {
			a[index + 1] = a[index--];
		}
		a[index + 1] = tmp;
	}
}
int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int a[10];
		for( int i = 0; i < 10; i++ )
			cin >> a[i];
		insertion_sort(a, 2, 5);
		for (int i = 2; i <= 5; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
		insert_sort( a, 10 );
		for( int i = 0; i < 10; i++ )
			cout << a[i] << " ";
		cout << endl;
	}
	system( "pause" );
	return 0;
}