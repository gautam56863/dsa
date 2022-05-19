#include <iostream>
using namespace std;

struct Node
{
    struct Node *pre;
    int data;
    struct Node *next;
} *first = nullptr;

void create(int A[], int n)
{
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->pre = NULL;
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->pre = last;
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void Display(struct Node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int length(struct Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;

    if (index < 0 || index > length(p))
    {
        return;
    }
    if (index == 0)
    {
        t = new Node;
        t->data = x;
        t->pre = NULL;
        t->next = first;
        first->pre = t;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t = new Node;
        t->data = x;

        t->pre = p;
        t->next = p->next;

        if (p->next)
            p->next->pre = t;
        p->next = t;
    }
}
int Delete(struct Node *p, int index)
{
    int x = -1;
    if (index < 1 || index > length(p))
        return -1;
    if (index == 1)
    {
        first = first->next;
        if (first)
            first->pre = NULL;

        x = p->data;
        delete[] p;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        p->pre->next = p->next;
        if (p->next)
            p->next->pre = p->pre;
        x = p->data;
        delete[] p;
    }
    return x;
}

void reverse(struct Node *p)
{
    Node *temp = new Node;
    while (p)
    {
        temp = p->next;
        p->next = p->pre;
        p->pre = temp;
        p = p->pre;
        if (p && p->next == NULL)
        {
            first = p;
        }
    }
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    Insert(first, 2, 25);
    Delete(first, 1);
    Display(first);
    reverse(first);
    Display(first);

    return 0;
}