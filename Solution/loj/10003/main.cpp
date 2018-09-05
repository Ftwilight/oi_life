#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1005;

struct Task
{
	int a, b, rank;
	bool operator< (Task const &o) const
	{
		return min(a, b) < min(o.a, o.b);
	}	
};

Task task[MAX];
int a[MAX], b[MAX];
int ans[MAX];

int main()
{
	//file
	//freopen("data.in", "r", stdin);
	//init
	int n;
	//input
	cin >>n;
	for(int i = 1; i <= n; ++i)
	{
		cin >>a[i];
		task[i].a = a[i];
		task[i].rank = i;
	}
	for(int i = 1; i <= n; ++i)
	{
		cin >>b[i];
		task[i].b = b[i];
	}
	//work
	sort(task+1, task+n+1);
	int front = 1, back = n;
	for(int i = 1; i <= n; ++i)
		if(task[i].a <= task[i].b)
			ans[front++] = task[i].rank;
		else
			ans[back--] = task[i].rank;
	
	int t = 0;
	int ma = 0, mb = 0;
	for(int i = 1; i <= n; ++i)
	{
		ma += a[ans[i]];
		if(ma > mb)
			mb = ma;
		mb += b[ans[i]];
	}
	//output
	printf("%d\n", mb);
	for(int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	//end
	return 0;
}
