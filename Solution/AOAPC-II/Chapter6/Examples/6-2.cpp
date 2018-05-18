#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int num;
    while(cin >>num && num != 0)
    {
        while(true)
        {
            queue<int> need;
            for(int i = 0; i < num; ++i)
            {
                int t;
                cin >>t;
                if(t == 0)
                    break;
                need.push(t);
            }
            if(need.empty())
            {
                cout <<"\n";
                break;
            }
            //work
            stack<int> s;
            for(int i = 1; i <= num; ++i)
            {
                s.push(i);
                while(!s.empty() && s.top() == need.front())
                {
                    s.pop();
                    need.pop();
                }
            }
            //output
            if(need.empty())
                cout <<"Yes\n";
            else
                cout <<"No\n";
        }
    }
    //end
    return 0;
}
