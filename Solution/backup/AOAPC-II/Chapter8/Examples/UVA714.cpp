#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

#define ll long long

using namespace std;

const int MAX = 550;
const ll INF = 5000000001;

ll book[MAX]; 
ll m, k;

bool judge(ll top);
ll find_ans();
void output(ll ans);


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
        scanf("%lld %lld", &m, &k);
        for(int i = 0; i < m; ++i)
            scanf("%lld", book+i);
        //work && output
        output(find_ans());
    }
    //end
    return 0;
}

ll find_ans()
{
    ll l = 1, r = INF;
    ll m;
    while(l < r)
    {
        m = ((l+r)>>1);
        if(judge(m))
            r = m;
        else
            l = m+1;
    }
    return l;
}

bool judge(ll top)
{
    ll sum = 0;
    ll cnt = 0;
    for(int i = 0; i < m; ++i)
    {
        if(book[i] > top)
            return false;
        if(sum + book[i] > top)
        {
            sum = book[i];
            ++cnt;
        }
        else
            sum += book[i];
    }
    return cnt <= k-1;
}

void output(ll ans)
{
    stack<ll> stk;
    ll sum = 0;
    --k;
    for(int i = m-1; i >= 0; --i)
    {
        if(i+1 == k)
        {
            stk.push(-1);
            stk.push(book[i]);
            --k;
        }
        else
        {
            if(sum+book[i] > ans)
            {
                stk.push(-1);
                --k;
                sum = 0;
            }
            stk.push(book[i]);
            sum += book[i];
        }
    }
    while(!stk.empty())
    {
        if(stk.top() == -1)
        {
            printf("/ ");
            stk.pop();
        }
        printf("%d", stk.top());
        stk.pop();
        if(!stk.empty())
            printf(" ");
    }
    printf("\n");
}
