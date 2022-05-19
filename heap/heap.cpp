#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void insert(int a[], int n)
{
    int i = n, temp = a[n];
    while (i > 1 && a[i / 2] < temp)
    {
        a[i] = a[i / 2];
        i = i / 2;
    }
    a[i] = temp;
}
int Delete(int A[], int n)
{
    int i, j, x, val;
    x = A[n];
    val = A[1];
    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = i * 2;
    while (j < n - 1)
    {
        if (A[j + 1] > A[j])
            j++;
        if (A[i] < A[j])
        {
            swap(A[i], A[j]);
            i = j;
            j = i * 2;
        }
        else
            break;
    }
    return val;
}
void Display(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    int a[] = {0, 10, 20, 30, 25, 5, 40, 35};
    Display(a, 8);
    for (int i = 2; i < 8; i++)
    {
        insert(a, i);
    }
    Display(a, 8);
    for (int i = 7; i >= 1; i--)
        Delete(a, i);
    Display(a, 8);
    return 0;
}