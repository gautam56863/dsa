#include <iostream>
#include "queue.h"
using namespace std;

struct Stack
{
    int size;
    int top;
    struct Node **S;
};

void Stackcreate(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S = new Node *[size];
    // st->S = (struct Node **)malloc(st->size * sizeof(struct Node *));
}

// void Display(struct Stack st)
// {
//     int i;
//     for (i = st.top; i >= 0; i--)
//         printf("%d ", st.S[i]);
//     printf("\n");
// }
void push(struct Stack *st, struct Node *x)
{
    if (st->top == st->size - 1)
        printf("Stack overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}
struct Node *pop(struct Stack *st)
{
    struct Node *x = NULL;

    if (st->top == -1)
        printf("Stack Underflow\n");
    else
    {
        x = st->S[st->top--];
    }
    return x;
}
// int peek(struct Stack st, int index)
// {
//     int x = -1;
//     if (st.top - index + 1 < 0)
//         printf("Invalid Index \n");
//     x = st.S[st.top - index + 1];

//     return x;
// }
int isEmptystack(struct Stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}
int isFullstack(struct Stack st)
{
    return st.top == st.size - 1;
}
// int stackTop(struct Stack st)
// {
//     if (!isEmpty(st))
//         return st.S[st.top];
//     return -1;
// }