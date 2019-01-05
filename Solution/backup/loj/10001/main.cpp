#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 30005;
const int MAX_H = 5000;

struct Line
{
	int b, e, t;
	bool operator< (Line const &o) const
	{
		return e < o.e;
	}
};
Line line[MAX_H];

bool visited[MAX];

int main()
{
	//file
	//freopen("data.in", "r", stdin);
	//input
	int n, h;
	scanf("%d\n%d", &n, &h);
	for(int i = 0; i < h; ++i)
		scanf("%d %d %d", &line[i].b, &line[i].e, &line[i].t);
	//work
	sort(line, line+h);
	int ans = 0;
	for(int i = 0; i < h; ++i)
	{
		Line &now = line[i];
		int tree = 0;
		for(int j = now.b; j <= now.e; ++j)
			if(visited[j])
				++tree;
		if(tree < now.t)
		{
			for(int j = now.e; j >= now.b && tree < now.t; --j)
				if(!visited[j])
				{
					visited[j] = true;
					++ans;
					++tree;
				}
		}
	}
	//output
	printf("%d", ans);
	//end
	return 0;
}
