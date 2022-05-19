#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} * Head;

void Create(int A[], int n)
{
    struct Node *t, *last;
    Head = new Node;
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *h)
{
    do
    {
        /* code */
        cout << h->data << " ";
        h = h->next;
    } while (h != Head);
    cout << endl;
}

void RDisplay(struct Node *h)
{
    static int flag = 0;
    if (h != Head || flag == 0)
    {
        flag = 1;
        cout << h->data << " ";
        RDisplay(h->next);
    }
    flag = 0;
}

int Length(struct Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;

    } while (p != Head);
    return len;
}
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > Length(p))
        return;

    if (index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        if (Head == NULL)
        {
            Head = t;
            Head->next = Head;
        }
        else
        {
            while (p->next != Head)
                p = p->next;
            p->next = t;
            t->next = Head;
            Head = t;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}
// int isLoop(struct Node *f)
// {
//     struct Node *p, *q;
//     p = q = f;

//     do
//     {
//         p = p->next;
//         q = q->next;
//         q = q ? q->next : q;
//     } while (p && q && p != q);

//     if (p == q)
//         return 1;
//     else
//         return 0;
// }

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    Create(A, 5);
    Insert(Head, 2, 10);
    RDisplay(Head);
    return 0;
}