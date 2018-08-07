#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const long long index[3] = {2, 3, 5};

typedef long long LL;

int main()
{
    priority_queue<LL, vector<LL>, greater<LL> > num;
    set<LL> record;
    num.push(1);
    record.insert(1);
    for(int i = 1; i < 1500; ++i)
    {
        LL x = num.top();
        num.pop();
        for(int j = 0; j < 3; ++j)
        {
            LL y = x * index[j];
            if(!record.count(y))
            {
                num.push(y);
                record.insert(y);
            }
        }
    }
    cout <<"The 1500'th ugly number is "<< num.top() <<".\n";
    return 0;
}
