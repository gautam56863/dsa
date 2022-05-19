#include <iostream>
#include "queue.h"
// #include "stack.h"
#include <stack>
#include <queue>
using namespace std;
struct Node *root = NULL;

void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    cout << "Enter root value ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        cout << "Enter Left Child of " << p->data << " ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        cout << "Enter Right Child of " << p->data << " ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preorder(struct Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}

void postorder(struct Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " ";
    }
}
// void Ipreorder(struct Node *p)
// {
//     struct Stack stk;
//     Stackcreate(&stk, 100);

//     while (p || !isEmptystack(stk))
//     {
//         if (p)
//         {
//             cout << p->data;
//             push(&stk, p);
//             p = p->lchild;
//         }
//         else
//         {
//             p = pop(&stk);
//             p = p->rchild;
//         }
//     }
// }
void iterativePreorder(Node *p)
{
    stack<Node *> stk;
    while (p != nullptr || !stk.empty())
    {
        if (p != nullptr)
        {
            cout << p->data << ", " << flush;
            stk.emplace(p);
            p = p->lchild;
        }
        else
        {
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}
void iterativeInorder(Node *p)
{
    stack<Node *> stk;
    while (p != nullptr || !stk.empty())
    {
        if (p != nullptr)
        {
            stk.emplace(p);
            p = p->lchild;
        }
        else
        {
            p = stk.top();
            stk.pop();
            cout << p->data << ", " << flush;
            p = p->rchild;
        }
    }
    cout << endl;
}
void LevelOrder(Node *p)
{
    struct Queue q;
    create(&q, 100);

    cout << p->data << " ";
    enqueue(&q, p);
    while (!isEmpty(q))
    {
        p = dequeue(&q);
        if (p->lchild)
        {
            cout << p->lchild->data << " ";
            enqueue(&q, p->lchild);
        }
        if (p->rchild)
        {
            cout << p->rchild->data << " ";
            enqueue(&q, p->rchild);
        }
    }
}
int Count(Node *root)
{
    if (root)
        return Count(root->lchild) + Count(root->rchild) + 1;
    return 0;
}
int height(Node *root)
{
    int x = 0;
    int y = 0;
    if (root == 0)
        return 0;
    x = height(root->lchild);
    y = height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
int LeafNode(Node *p)
{
    int x = 0, y = 0;
    if (p)
    {
        LeafNode(p->lchild);
        LeafNode(p->rchild);
        if (p->lchild == NULL && p->rchild == NULL)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}
int NodeWithDegree2(Node *p)
{
    int x = 0, y = 0;
    if (p)
    {
        NodeWithDegree2(p->lchild);
        NodeWithDegree2(p->rchild);
        if (p->lchild != NULL && p->rchild != NULL)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}
int main()
{

    Treecreate();
    LevelOrder(root);
    cout << endl;
    // Ipreorder(root);
    cout << Count(root) << endl;
    cout << height(root) << endl;
    return 0;
}