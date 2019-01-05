#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	//file
	//freopen("data.in", "r", stdin);
	//init
	priority_queue<int, vector<int>, less<int> > minn;
	priority_queue<int, vector<int>, greater<int> > maxx;
	int n, t;
	//input
	cin >>n;
	for(int i = 0; i < n; ++i)
	{
		cin >>t;
		minn.push(t);
		maxx.push(t);
	}
	//work
	int a, b;
	while(minn.size() > 1)
	{
		a = minn.top();
		minn.pop();
		b = minn.top();
		minn.pop();
		minn.push(a * b + 1);
	}
	while(maxx.size() > 1)
	{
		a = maxx.top();
		maxx.pop();
		b = maxx.top();
		maxx.pop();
		maxx.push(a * b + 1);
	}
	//output
	cout <<maxx.top() - minn.top();
	//end
	return 0;
}
