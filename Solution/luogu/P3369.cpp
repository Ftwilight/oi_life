#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

class Treap
{
private:
    struct Node
    {
        int val, rank;
        int size, cnt;
        Node *ls, *rs;
        Node(int v=0, int r=0):val(v), rank(r), size(1), cnt(1), ls(NULL), rs(NULL)
        {}
    };
    Node *root, *nullnode;
    int GenRank()
    {
        return rand();
    }
    Node* newNode(int v=0, int r=0)
    {
        Node *ret = new Node(v, r);
        ret->ls = ret->rs = nullnode;
        return ret;
    }
    void PushUp(Node *n)
    {
        n->size = n->ls->size + n->rs->size + n->cnt;
    }
    void Lrot(Node *&n)
    {
        Node *nex = n->rs;
        nex->size = n->size;
        n->rs = nex->ls;
        nex->ls = n;
        PushUp(n);
        n = nex;
    }
    void Rrot(Node *&n)
    {
        Node *nex = n->ls;
        nex->size = n->size;
        n->ls = nex->rs;
        nex->rs = n;
        PushUp(n);
        n = nex;
    }
    void insert_(int v, Node *&now)
    {
        if(!now || now == nullnode)
        {
            now = newNode(v, GenRank());
            return;
        }
        ++(now->size);
        if(v == now->val)
            ++(now->cnt);
        else if(v < now->val)
        {
            insert_(v, now->ls);
            if(now->ls->rank < now->rank)
                Rrot(now);
        }
        else
        {
            insert_(v, now->rs);
            if(now->rs->rank < now->rank)
                Lrot(now);
        }
    }
    void del_(int v, Node *&now)
    {
        if(now == nullnode)
            return;
        if(now->val == v)
        {
            if(now->cnt > 1)
            {
                --(now->size);
                --(now->cnt);
                return;
            }
            if(now->ls == nullnode || now->rs == nullnode)
            {
                Node *t = now;
                now = (now->ls != nullnode)? now->ls: now->rs;
                delete t;
                return;
            }
            if(now->ls->rank < now->rank)
            {
                Rrot(now);
                del_(v, now);
            }
            else
            {
                Lrot(now);
                del_(v, now);
            }
        }
        else
        {
            --(now->size);
            if(v < now->val)
                del_(v, now->ls);
            else
                del_(v, now->rs);
        }
    }
    Node* find(int v)
    {
        Node *now = root;
        while(now != nullnode && now->val != v)
            now = (v < now->val)? now->ls: now->rs;
        return now;
    }
    int findMax(Node *n)
    {
        while(n->rs != nullnode)
            n = n->rs;
        return n->val;
    }
    int findMin(Node *n)
    {
        while(n->ls != nullnode)
            n = n->ls;
        return n->val;
    }
    int getRank_(int v, Node *now)
    {
        if(now == nullnode)
            return 0;
        if(now->val == v)
            return now->ls->size + 1;
        else if(now->val > v)
            return getRank_(v, now->ls);
        return now->ls->size + now->cnt + getRank_(v, now->rs);
    }
    int getKth_(int k, Node *now)
    {
        if(now == nullnode)
            return 0;
        if(k <= now->ls->size)
            return getKth_(k, now->ls);
        if(k > now->ls->size + now->cnt)
            return getKth_(k - now->cnt - now->ls->size, now->rs);
        return now->val;
    }
public:
    Treap():root(NULL)
    {
        nullnode = new Node();
        nullnode->ls = nullnode->rs = nullnode;
        nullnode->size = nullnode->cnt = 0;
    }
    void insert(int v)
    {
        insert_(v, root);
    }
    void del(int v)
    {
        del_(v, root);
    }
    int getRank(int v)
    {
        return getRank_(v, root);
    }
    int getKth(int k)
    {
        return getKth_(k, root);
    }
    int getPre(int v)
    {
        Node *now = root;
        int ans = 0;
        while(now != nullnode)
        {
            if(v > now->val)
            {
                ans = now->val;
                now = now->rs;
            }
            else
                now = now->ls;
        }
        return ans;
    }
    int getSub(int v)
    {
        Node *now = root;
        int ans = 0;
        while(now != nullnode)
        {
            if(v < now->val)
            {
                ans = now->val;
                now = now->ls;
            }
            else
                now = now->rs;
        }
        return ans;
    }
}treap;

int main()
{
    // freopen("data.in", "r", stdin);
    int n, op, x;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d", &op, &x);
        switch(op)
        {
        case 1:
            treap.insert(x);
            break;
        case 2:
            treap.del(x);
            break;
        case 3:
            printf("%d\n", treap.getRank(x));
            break;
        case 4:
            printf("%d\n", treap.getKth(x));
            break;
        case 5:
            printf("%d\n", treap.getPre(x));
            break;
        case 6:
            printf("%d\n", treap.getSub(x));
            break;
        }
    }
    return 0;
}
