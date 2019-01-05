#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 15005;

struct Seg
{
	double s, e;
	bool operator<(const Seg &o) const
	{
		return s < o.s;
	}
};

Seg seg[MAX];

int main()
{
	//file
	//freopen("data.in", "r", stdin);
	//init
	int n;
	double l, w;
	int T;
	cin >>T;
	while(T--)
	{
		//input
		int cnt = 0;
		cin >>n >>l >>w;
		for(int i = 0; i < n; ++i)
		{
			double p, r, len;
			cin >>p >>r;
			if(r > w/2)
			{
				len = sqrt(r*r - (w/2)*(w/2));
				seg[cnt].s = p - len;
				seg[cnt++].e = p + len;
			}
		}
		//work
		sort(seg, seg+cnt);
		int ans = 0, i = 0;
		double end = 0.0;
		bool flag = true;
		while(end < l)
		{
			++ans;
			double backup = end;
			for( ; i < cnt && seg[i].s <= backup; ++i)
				end = max(end, seg[i].e);
			if(end == backup && end < l)
			{
				flag = false;
				break;
			}
		}
		//output
		if(flag)
			printf("%d\n", ans);
		else
			printf("-1\n");
	}
	//end
	return 0;
}
