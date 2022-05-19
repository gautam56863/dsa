#include <iostream>
#define SIZE 10
using namespace std;

int hash_func(int key)
{
    return key % SIZE;
}

int probe(int H[], int key)
{
    int index = hash_func(key);
    int i = 0;
    while (H[(index + i) % SIZE] != 0)
        i++;
    return (index + i) % SIZE;
}
void Insert(int H[], int key)
{
    int index = hash_func(key);
    if (H[index] != 0)
        index = probe(H, key);
    H[index] = key;
}
int Search(int H[], int key)
{
    int index = hash_func(key);
    int i = 0;
    while (H[(index + i) % SIZE] != key && H[(index + i) % SIZE] != 0)
        i++;
    if (H[(index + i) % SIZE] == 0)
        return -1;
    return (index + i) % SIZE;
}
void Display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    int H[10] = {0};
    Insert(H, 12);
    Insert(H, 25);
    Insert(H, 35);
    Insert(H, 26);
    Display(H, 10);
    cout << Search(H, 27);
    return 0;
}