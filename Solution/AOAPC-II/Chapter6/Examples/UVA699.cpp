#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 510;

int sum[MAX];

void build(int now);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int v, cnt = 0;
    while(scanf("%d", &v) && v != -1)
    {
        //work
        memset(sum, 0, sizeof(sum));
        sum[MAX >> 2] += v;
        build((MAX >> 2) - 1);
        build((MAX >> 2) + 1);
        //output
        printf("Case %d:\n", ++cnt);
        int p = 0;
        while(!sum[p])
            ++p;
        printf("%d", sum[p]);
        while(sum[++p])
            printf(" %d", sum[p]);
        printf("\n\n");
    }
    //end
    return 0;
}

void build(int now)
{
    int v;
    scanf("%d", &v);
    if(v == -1)
        return;
    sum[now] += v;
    build(now - 1);
    build(now + 1);
}
