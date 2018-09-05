#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1005;

struct Act
{
	int b, e;
	bool operator<(Act const &o) const
	{
		return e < o.e;
	}
};
Act act[MAX];

int main()
{
	//file
	//freopen("data.in", "r", stdin);
	//input
	int n;
	cin >>n;
	for(int i = 0; i < n; ++i)
		cin >>act[i].b >>act[i].e;
	//work
	sort(act, act+n);
	int ans = 1;
	int end = act[0].e;
	for(int i = 1; i < n; ++i)
		if(act[i].b >= end)
		{
			++ans;
			end = act[i].e;
		}
	//output
	cout <<ans;
	//end
	return 0;
}
