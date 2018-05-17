#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <map>
#include <assert.h>

using namespace std;

const int MAX = 1010;

int team[MAX];

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int n, cnt = 0;
    while(cin >>n && n != 0)
    {
        cout <<"Scenario #" <<(++cnt) <<"\n";
        map<int, int> team;
        for(int i = 1; i <= n; ++i)
        {
            int size;
            cin >>size;
            for(int j = 0; j < size; ++j)
            {
                int t;
                cin >>t;
                team[t] = i;
            }
        }
        queue<int> q, tq[MAX];
        string op;
        while(cin >>op && op != "STOP")
        {
            //work
            if(op[0] == 'E')
            {
                int t;
                cin >>t;
                if(!tq[team[t]].size())
                    q.push(team[t]);
                tq[team[t]].push(t);
            }
            else
            {
                cout <<tq[q.front()].front() <<"\n";
                tq[q.front()].pop();
                if(!tq[q.front()].size())
                    q.pop();
            }
        }
        cout <<"\n";
    }
    //end
    return 0;
}
