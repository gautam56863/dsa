#include <iostream>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
} *root = NULL;

int NodeHeight(Node *p)
{
    int hl, rl;
    hl = p && p->lchild ? p->lchild->height : 0;
    rl = p && p->rchild ? p->rchild->height : 0;

    return hl > rl ? hl + 1 : rl + 1;
}
int BalanceFactor(Node *p)
{
    int hl, rl;
    hl = p && p->lchild ? p->lchild->height : 0;
    rl = p && p->rchild ? p->rchild->height : 0;

    return hl - rl;
}
Node *LLRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p)
        root = pl;

    return pl;
}
Node *RRRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    // Update height
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    // Update root
    if (root == p)
    {
        root = pr;
    }
    return pr;
}

Node *LRRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    // Update height
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    // Update root
    if (p == root)
    {
        root = plr;
    }
    return plr;
}

Node *RLRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    // Update height
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    // Update root
    if (root == p)
    {
        root = prl;
    }
    return prl;
}

Node *RInsert(Node *p, int key)
{
    Node *t = NULL;
    if (p == nullptr)
    {
        t = new Node;
        t->data = key;
        t->height = 1;
        t->lchild = nullptr;
        t->rchild = nullptr;
        return t;
    }

    if (key < p->data)
    {
        p->lchild = RInsert(p->lchild, key);
    }
    else if (key > p->data)
        p->rchild = RInsert(p->rchild, key);

    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if ((BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1))
        return LRRotation(p);
    else if ((BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1))
        return RRRotation(p);
    else if ((BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1))
        return RLRotation(p);
    return p; // key == p->data?
}

int main()
{
    root = RInsert(root, 10);
    RInsert(root, 20);
    RInsert(root, 30);
    RInsert(root, 25);
    RInsert(root, 28);
    RInsert(root, 27);
    RInsert(root, 5);

    cout << root->data;
    return 0;
}