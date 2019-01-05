#include <cstdio>
#include <cstring>
#include <iostream>

const int MAX = 70;
const int INf = 0x3f3f3f3f;

int stick[MAX];
int n, max_len, min_len, sum;
int all, each;

bool dfs(int cnt, int len, int last);

int main()
{
	//file
	//freopen("data.in", "r", stdin);
	//input
	int t;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &t);
		if(t <= 50)
		{
			++stick[t];
			max_len = std::max(max_len, t);
			min_len = std::min(min_len, t);
			sum += t;
		}
	}
	//work
	for(int i = max_len; i <= sum; ++i)
		if(!(sum % i))
		{
			each = i;
			all = sum / i;
			if(dfs(1, 0, max_len))
				break;
		}
	//output
	printf("%d", each);
	//end
	return 0;
}

bool dfs(int cnt, int len, int last)
{
	if(cnt == all)
		return true;
	if(len == each)
		return dfs(cnt+1, 0, max_len);
	
	for(int i = last; i >= min_len; --i)
		if(stick[i] && len+i <= each)
		{
			--stick[i];
			if(dfs(cnt, len+i, i))
				return true;
			++stick[i];
			if(!len || len+i == each)
				return false;
		}
	
	return false;
}
