#include <iostream>
using namespace std;
void move(int count, int start, int finish, int temp);
int main(int argc, char const *argv[])
{
	while(1) {
		int disks;
		cin >> disks;
		move(disks, 1, 3, 2);	
	}
	return 0;
}
void move(int count, int start, int finish, int temp) {
	if (count > 0)
	{
		move(count - 1, start, temp, finish);
		cout << "Move disk " << count << " from " 
		<< start << " to " << finish << "." << endl;
		move(count - 1, temp, finish, start);
	}
}