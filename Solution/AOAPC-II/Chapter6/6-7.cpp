#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
    int v;
    Node *left, *right;
    Node():v(0), left(NULL), right(NULL)
    {}
};

Node *root;
bool fail;
vector<int> ans;

void addnode(int v, char *path);
bool input();
void bfs();
void output();

inline void init();
inline Node* newnode();
void remove(Node *node);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    root = newnode();
    while(input())
    {
        bfs();
        output();
        init();
    }
    //end
    return 0;
}

inline Node* newnode()
{
    return new Node;
}

void remove(Node *node)
{
    if(node == NULL)
        return;
    else
    {
        remove(node -> left);
        remove(node -> right);
        delete node;
        root = newnode();
    }
}

inline void init()
{
    fail = false;
    remove(root);
    root = newnode();
    ans.clear(); 
}

void addnode(int v, char *path)
{
    int len = strlen(path);
    Node *now = root;
    for(int i = 0; i < len - 1; ++i)
    {
        if(path[i] == 'L')
        {
            if(now -> left == NULL)
                now->left = newnode();
            now = now -> left;
        }
        else if(path[i] == 'R')
        {
            if(now -> right == NULL)
                now->right = newnode();
            now = now -> right;
        }
    }
    if(now -> v)
        fail = true;
    now -> v = v;
}

bool input()
{
    char s[20];
    while(true)
    {
        if(scanf("%s", s) != 1)
            return false;
        if(!strcmp(s, "()"))
            break;
        int v;
        sscanf(&s[1], "%d", &v);
        addnode(v, strchr(s, ',')+1);
    }
    return true;
}

void bfs()
{
    queue<Node*> node;
    node.push(root);
    while(!node.empty())
    {
        Node *now = node.front();
        if(now -> v == 0)
        {
            fail = true;
            return;
        }
        ans.push_back(now -> v);
        if(now -> left)
            node.push(now -> left);
        if(now -> right)
            node.push(now -> right);
        node.pop();
    }
}

void output()
{
    if(fail)
        printf("not complete\n");
    else
    {
        for(int i = 0; i < ans.size(); ++i)
        {
            printf("%d", ans[i]);
            if(i != ans.size() - 1)
                printf(" ");
        }
        printf("\n");
    }
}
