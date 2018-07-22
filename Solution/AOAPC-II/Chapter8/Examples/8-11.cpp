#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int n;
    while(cin >>n && n)
    {
        priority_queue<int, vector<int>, greater<int> > work;
        int t;
        for(int i = 0; i < n; ++i)
        {
            cin >>t;
            work.push(t);
        }
        //work
        int ans = 0;
        for(int i = 0; i < n-1; ++i)
        {
            int t1 = work.top();
            work.pop();
            int t2 = work.top();
            work.pop();
            ans += t1+t2;
            work.push(t1+t2);
        }
        //output
        printf("%d\n", ans);
    }
    //end
    return 0;
}
