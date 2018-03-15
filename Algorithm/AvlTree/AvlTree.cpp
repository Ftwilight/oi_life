#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *lc;
    Node *rc;
    int height;
    int size;
    Node(int val=0):data(val), lc(NULL), rc(NULL), height(0), size(1){}
};

class AvlTree
{
private:
    int GetHeight(Node *aim);
    int GetSize(Node *aim);
    Node* search(int num);
    Node* FindMax(Node *aim);
    Node* FindMin(Node *aim);
    Node* ll(Node *aim);
    Node* rr(Node *aim);
    Node* lr(Node *aim);
    Node* rl(Node *aim);
    void balance(Node *aim);
public:
    Node *root;
    AvlTree(){}
    ~AvlTree(){}
    void insert(int num, Node *now);
    bool del(int data, Node* aim);
    int find_rank(int num);
    int find_num(int rank);
    int find_pre(int k);
    int find_sub(int k);
};

int AvlTree:: GetHeight(Node *aim)
{
    if(aim == NULL)
        return -1;
    else
        return aim->height;
}

int AvlTree:: GetSize(Node *aim)
{
    return aim->size;
}

Node* AvlTree::search(int num)
{
    Node *now = root;
    while(now->data != num)
    {
        if(num < now->data)
            now = root->lc;
        else
            now = root->rc;
    }
    return now;
}

Node* AvlTree::FindMax(Node *aim)
{
    if(aim->rc)
        FindMax(aim->rc);
    else
        return aim;
}

Node* AvlTree::FindMin(Node *aim)
{
    if(aim->lc)
        FindMax(aim->lc);
    else
        return aim;
}

Node* AvlTree::ll(Node *aim)
{
    aim->lc->size += 1 + aim->rc->size;
    aim->size = aim->size - aim->lc->size + aim->lc->rc->size;
    Node *newHead = aim->lc;
    aim->lc = newHead->rc;
    newHead->rc = aim;
    aim = newHead;
    aim->height = max(GetHeight(aim->rc), GetHeight(aim->lc)) + 1;
    newHead->height = max(GetHeight(newHead->rc), GetHeight(newHead->lc)) + 1;
}

Node* AvlTree::rr(Node *aim)
{
    aim->rc->size += 1 + aim->lc->size;
    aim->size = aim->size - aim->lc->size + aim->rc->lc->size;
    Node *newHead = aim->rc;
    aim->rc = newHead->lc;
    newHead->lc = aim;
    aim = newHead;
    aim->height = max(GetHeight(aim->rc), GetHeight(aim->lc)) + 1;
    newHead->height = max(GetHeight(newHead->rc), GetHeight(newHead->lc)) + 1;
}

Node* AvlTree::lr(Node *aim)
{
    rr(aim->lc);
    return ll(aim);
}

Node* AvlTree::rl(Node *aim)
{
    ll(aim->rc);
    return rr(aim);
}

void AvlTree::balance(Node *aim)
{
    if(GetHeight(aim->lc) - GetHeight(aim->rc) > 1)
        if(aim->data < aim->lc->data)
            aim = ll(aim);
        else
            aim = lr(aim);
    else if(GetHeight(aim->rc) - GetHeight(aim->lc) > 1)
        if(aim->data > aim->rc->data)
            aim = rr(aim);
        else
            aim = rl(aim);
}

void AvlTree::insert(int num, Node *now)
{
    if(now == NULL)
        now = new Node(num);
    else if(num < now->data)
        insert(num, now->lc);
    else if(num > now->data)
        insert(num, now->rc);
    balance(now);
    now->height = max(GetHeight(now->lc), GetHeight(now->rc)) + 1;
}

bool AvlTree::del(int data, Node *aim)
{
    if(aim == NULL)
        return false;
    else if(aim->data == data)
    {
        if(aim->lc && aim->rc)
            if(GetHeight(aim->rc) > GetHeight(aim->lc))
            {
                aim->data = FindMin(aim->rc)->data;
                del(aim->data, aim->rc);
            }
            else
            {
                aim->data = FindMax(aim->lc)->data;
                del(aim->data, aim->lc);
            }
        else
        {
            Node* old = aim;
            aim = (aim->lc)? aim->lc: aim->rc;
            delete old;
        }
    }
    else if(data < aim->data)
    {
        del(data, aim->lc);
        balance(aim);
    }
    else if(data > aim->data)
    {
        del(data, aim->rc);
        balance(aim);
    }
}

int AvlTree::find_rank(int num)
{
    return search(num)->lc->size + 1;
}

int AvlTree::find_pre(int num)
{
    return search(num)->size;
}

int AvlTree::find_sub(int num)
{
    Node *node = search(num);
    return FindMin(node->rc)->data;
}
