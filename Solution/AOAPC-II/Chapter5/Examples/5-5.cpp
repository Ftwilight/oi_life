#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

using namespace std;

map<set<int>, int> IDcache;
vector<set<int> > setcache;

inline int ID(set<int> x);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int all;
    cin >>all;
    while(all--)
    {
        //work
        IDcache.clear();
        setcache.clear();
        stack<int> s;
        int n;
        cin >>n;
        while(n--)
        {
            string oper;
            cin >>oper;
            if(oper[0] == 'P')
                s.push(ID(set<int>()));
            else if(oper[0] == 'D')
                s.push(s.top());
            else
            {
                set<int> res;
                set<int> t1 = setcache[s.top()];
                s.pop();
                set<int> t2 = setcache[s.top()];
                s.pop();
                if(oper[0] == 'U')
                    set_union(ALL(t1), ALL(t2), INS(res));
                else if(oper[0] == 'I')
                    set_intersection(ALL(t1), ALL(t2), INS(res));
                else if(oper[0] == 'A')
                {
                    res = t2;
                    res.insert(ID(t1));
                }
                s.push(ID(res));
            }
            cout <<setcache[s.top()].size() <<"\n";
        }
        cout <<"***\n";
    }
    //end
    return 0;
}

inline int ID(set<int> x)
{
    if(IDcache.count(x))
        return IDcache[x];
    else
    {
        setcache.push_back(x);
        return IDcache[x] = setcache.size() - 1;
    }
}


