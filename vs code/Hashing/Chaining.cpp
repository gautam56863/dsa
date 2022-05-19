#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node *next;
};
// } *first = NULL, *second = nullptr, *third = nullptr;
int count(struct Node *p);
void SortedInsert(struct Node **p, int x);
int Lsearch(struct Node *p, int key);
void Delete(Node *H[], int key);
int hash_func(int key);
void Insert(Node *HT[], int key);

int count(struct Node *p)
{
	int c = 0;
	while (p)
	{
		c++;
		p = p->next;
	}
	return c;
}
void SortedInsert(struct Node **p, int x)
{
	struct Node *t, *q = NULL;
	t = new Node;
	t->data = x;
	t->next = NULL;

	if (*p == NULL)
		*p = t;
	else
	{
		Node *first = *p;
		while (first && first->data < x)
		{
			q = first;
			first = first->next;
		}
		if (q == NULL)
		{
			t->next = *p;
			*p = t;
		}
		else
		{
			t->next = q->next;
			q->next = t;
		}
	}
}
int Lsearch(struct Node *p, int key)
{
	while (p)
	{
		if (key == p->data)
			return p->data;
		p = p->next;
	}
	return -1;
}

void Delete(Node *H[], int key)
{
	int index = hash_func(key);
	Node *p = H[index];
	struct Node *q = nullptr;
	int x = -1;
	if (index < 1 || index > 10)
		return;
	if (p->data == key)
	{
		q = p;
		p = p->next;
		delete q;
		H[index] = p;
	}
	else
	{
		while (p && p->data != key)
		{
			q = p;
			p = p->next;
		}

		q->next = p->next;
		delete p;
	}
}

int hash_func(int key)
{
	return key % 10;
}

void Insert(Node *HT[], int key)
{
	int index = hash_func(key);
	SortedInsert(&HT[index], key);
}

int main()
{
	Node *HT[10];
	for (int i = 0; i < 10; i++)
	{
		HT[i] = NULL;
	}

	Insert(HT, 22);
	Insert(HT, 42);
	Insert(HT, 12);
	Insert(HT, 72);
	cout << Lsearch(HT[hash_func(22)], 12) << endl;
	Delete(HT, 12);
	cout << Lsearch(HT[hash_func(22)], 12) << endl;
	cout << Lsearch(HT[hash_func(22)], 22) << endl;
	cout << Lsearch(HT[hash_func(22)], 42) << endl;
	// cout << temp->data;
	return 0;
}