/*
墓地雕塑：在一个周长为10000的圆上等距分布着n个雕塑。现在又有m个雕塑加入，
希望所有n+m个雕塑在圆周上均匀分布。求n个雕塑移动的总距离最小。
 */
/*
输入：
2 1
2 3
3 1
输出：
1666.6667
1000.0
1666.6667

 */
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) == 2) {
		double ans = 0.0;
		for (int i = 1; i < n; i++) {
			double pos = (double)i / n * (n + m);
			ans += fabs(pos - floor(pos + 0.5)) / (n + m);
		}
		printf("%.4lf\n", ans * 10000);
	}
	return 0;
}