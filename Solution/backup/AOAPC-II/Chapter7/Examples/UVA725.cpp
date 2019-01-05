#include <cstdio>
#include <cstring>

const int MAX = 100000;

bool judge(char *a, char *b);
void work(int n);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int n;
    scanf("%d", &n);
    work(n);
    while(scanf("%d", &n) == 1 && n)
    {
       printf("\n");
       work(n);
    }
    //end
    return 0;
}

bool judge(char *a, char *b)
{
    int busket[10];
    memset(busket, 0, sizeof(busket));
    int len = strlen(a);
    for(int i = 0; i < len; ++i)
    {
        if(++busket[a[i]-'0'] > 1 || ++busket[b[i]-'0'] > 1)
            return false;
    }
    return true;
}

void work(int n)
{
    //enum
    char buf_a[10], buf_b[10];
    bool flag = true;
    for(int i = 1234; i < MAX; ++i)
    {
        int j = n * i;
        sprintf(buf_b, "%05d", i);
        sprintf(buf_a, "%05d", j);
        if(judge(buf_a, buf_b))
        {
            flag = false;
            //output
            printf("%05d / %05d = %d\n", j, i, n);
        }
    }
    if(flag)
        printf("There are no solutions for %d.\n", n);
}
