#include <iostream>
#include <deque>
using namespace std;
struct node
{
	int priority;
	int position;
};
int main(int argc, char const *argv[])
{
	int t, n, m;
	int sum = 0;
	deque<node> jobs;
	struct node job[101];
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		jobs.clear();
		sum = 0;
		cin >> n >> m;
		for (int j = 0; j < n; ++j)
		{
			cin >> job[j].priority;
			job[j].position = j;
		}
		for (int j = 0; j < n; ++j)
		{
			jobs.insert(jobs.end(), job[j]);
		}
		for (int k = 0; k < 10000; ++k)
		{
			if (jobs.size() != 0)
			{
				bool flag = false;
				for (int j = 0; j < jobs.size(); ++j)
				{
					if (jobs[0].priority < jobs[j].priority)
					{
						flag = true;
						break;
					}
				}
				if (flag == true)
				{
					struct node temp = jobs[0];
					jobs.erase(jobs.begin());
					jobs.insert(jobs.end(), temp);
				}
				else {
					struct node temp = jobs[0];
					jobs.erase(jobs.begin());
					sum++;
					if (temp.position == m)
					{
						cout << sum << endl;
						break;
					}
				}
			}
		}
	}
	return 0;
}