#include <iostream>
#include <cstdio>
#include <algorithm>

const int MAX = 501;

struct Task
{
	int lim, pun;
	bool operator<(const Task &o) const
	{
		return pun > o.pun;
	}
};
Task task[MAX];
bool have_task[MAX];

int main()
{
	//file
	//freopen("data.in", "r", stdin);
	//init
	int m, n;
	//input
	scanf("%d %d", &m, &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &task[i].lim);
	for(int i = 0; i < n; ++i)
		scanf("%d", &task[i].pun);
	//work
	std::sort(task, task+n);
	int ans = 0;
	for(int i = 0; i < n; ++i)
	{
		bool flag = true;
		for(int j = task[i].lim; j > 0; --j)
			if(!have_task[j])
			{
				have_task[j] = true;
				flag = false;
				break;
			}
		if(flag)
		{
			ans += task[i].pun;
			for(int j = n; j > 0; --j)
				if(!have_task[j])
				{
					have_task[j] = true;
					break;
				}
		}
	}
	//output
	ans = m - ans;
	printf("%d\n", ans);
	//end
	return 0;
}
