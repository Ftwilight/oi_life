#include <cstdio>
#include <iostream>
#include <set>

const int MAX = 1000005;

int num[MAX];

int main()
{
	//file
	//freopen("data.in", "r", stdin);
	//input
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", num+i);
	//work
	int l = 0, ans = 0;
	std::set<int> record;
	for(int r = 0; r < n; ++r)
	{
		if(!record.count(num[r]))
		{
			record.insert(num[r]);
			ans = std::max(ans, r-l+1);
		}
		else
		{
			while(l < r && record.count(num[r]))
				record.erase(num[l++]);
		}
	}
	//output
	printf("%d", ans);
	//end
	return 0;
}
