#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX = 5050;

struct inv
{
    int b, e;
    int rank;
    inv(int a=0, int b=0, int c=0):b(a), e(b), rank(c)
    {};
    bool operator< (const inv &other) const
    {
        if(e != other.e)
            return e < other.e;
        else
            return b > other.b;
    }
};

inv line[MAX], col[MAX];
pair<int, int> rook[MAX];
bool l[MAX], c[MAX];

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    //input
    int size;
    int xl, yl, xr, yr;
    while(scanf("%d", &size) == 1 && size)
    {
        for(int i = 0; i < size; ++i)
        {
            scanf("%d %d %d %d", &line[i].b, &col[i].b, &line[i].e, &col[i].e);
            line[i].rank = col[i].rank = i;
        }
        //work
        memset(l, 0, sizeof(l));
        memset(c, 0, sizeof(c));
        sort(line, line+size);
        sort(col, col+size);
        int cnt = 0;
        for(int i = 0; i < size; ++i)
        {
            bool flag1=false, flag2=false;
            for(int j = line[i].b; j <= line[i].e; ++j)
                if(!l[j])
                {
                    rook[line[i].rank].first = j;
                    l[j] = flag1 = true;
                    break;
                }
            for(int j = col[i].b; j <= col[i].e; ++j)
                if(!c[j])
                {
                    rook[col[i].rank].second = j;
                    c[j] = flag2 = true;
                    break;
                }
            if(flag1 && flag2)
                ++cnt;
        }
        //output
        if(cnt == size)
            for(int i = 0; i < size; ++i)
                printf("%d %d\n", rook[i].first, rook[i].second);
        else
            printf("IMPOSSIBLE \n");
    }
    //end
    return 0;
}
