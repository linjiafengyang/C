#include <iostream>
using namespace std;
int main() {
	int n;
	int jia = 0, yi = 0;
	int jiahan, jiahua;
	int yihan, yihua;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> jiahan >> jiahua >> yihan >> yihua;
		if (jiahan + yihan == jiahua && jiahan + yihan != yihua) {
			yi++;
		}
		if (jiahan + yihan != jiahua && jiahan + yihan == yihua) {
			jia++;
		}
	}
	cout << jia << " " << yi;
	return 0;
}