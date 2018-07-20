#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 4020;
const int INF = 0x7fffffff;

int num[4][MAX];
int sum1[MAX*MAX], sum2[MAX*MAX];

int find_sum(int val, int len);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    //input
    int cnt;
    scanf("%d", &cnt);
    while(cnt--)
    {
        int size;
        scanf("%d", &size);
        for(int i = 0; i < size; ++i)
            for(int j = 0; j < 4; ++j)
                scanf("%d", num[j]+i);
        //work
        int len = 0;
        for(int i = 0; i < size; ++i)
            for(int j = 0; j < size; ++j)
            {
                sum1[len] = num[0][i]+num[1][j];
                sum2[len++] = -num[2][i]-num[3][j];
            }
        //sort(sum1, sum1+len);
        sort(sum2, sum2+len);
        int ans = 0;
        for(int i = 0; i < len; ++i)
            ans += find_sum(sum1[i], len);
        //output
        printf("%d\n", ans);
        if(cnt)
            printf("\n");
    }
    //end
    return 0;
}

int find_sum(int val, int len)
{
    int l = 0;
    int r = len-1;
    int mid;
    while(l < r)
    {
        mid = (r+l)>>1;
        if(sum2[mid] < val)
            l = mid+1;
        else
            r = mid;
    }
    int ans = 0;
    for(int i = l; sum2[i]==val && i < len; ++i)
        ++ans;
    return ans;
}
