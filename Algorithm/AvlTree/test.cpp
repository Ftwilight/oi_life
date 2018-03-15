#include "AvlTree.cpp"
#include <iostream>

using namespace std;

int main()
{
    AvlTree tree;
    int num;
    cin >>num;
    for(int i=0; i<num; ++i)
    {
        int op, n;
        cin >>op >>n;
        switch(op)
        {
            case 1:
                tree.insert(n, tree.root);
                break;
            case 2:
                tree.del(n, tree.root);
                break;
            case 3:
                cout <<tree.find_rank(n) <<"\n";
                break;
            case 4:
                break;
            case 5:
                cout <<tree.find_pre(n) <<"\n";
                break;
            case 6:
                cout <<tree.find_sub(n) <<"\n";
                break;
        }
    }
}
