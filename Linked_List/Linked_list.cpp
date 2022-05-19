#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node *next;
} *first = NULL, *second = nullptr, *third = nullptr;
void create(int A[], int n)
{
	struct Node *t, *last;
	first = new Node;
	first->data = A[0];
	first->next = NULL;
	last = first;

	for (int i = 1; i < n; i++)
	{
		t = new Node;
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}
void create2(int A[], int n)
{
	int i;
	struct Node *t, *last;
	second = new Node;
	second->data = A[0];
	second->next = NULL;
	last = second;

	for (i = 1; i < n; i++)
	{
		t = new Node;
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}
void Display(struct Node *p)
{
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void RDisplay(struct Node *p)
{
	if (p != NULL)
	{
		cout << p->data << " ";
		RDisplay(p->next);
	}
}
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
int Rcount(struct Node *p)
{
	if (!p)
		return 0;
	return Rcount(p->next) + 1;
}
int sum(struct Node *p)
{
	int s = 0;
	while (p)
	{
		s += p->data;
		p = p->next;
	}
	return s;
}
int Rsum(struct Node *p)
{
	if (!p)
		return 0;
	return Rsum(p->next) + p->data;
}
int max(struct Node *p)
{
	int m = INT32_MIN;
	while (p)
	{
		if (p->data > m)
			m = p->data;
		p = p->next;
	}
	return m;
}
int Rmax(struct Node *p)
{
	int x = 0;
	if (p == 0)
		return INT32_MIN;
	x = Rmax(p->next);
	if (x > p->data)
		return x;
	else
		return p->data;
}
struct Node *Lsearch(struct Node *p, int key)
{
	struct Node *q;
	while (p)
	{
		if (key == p->data)
		{
			q->next = p->next;
			p->next = first;
			first = p;
			return p;
		}
		q = p;
		p = p->next;
	}
	return NULL;
}
struct Node *RLsearch(struct Node *p, int key)
{
	if (p == NULL)
		return NULL;
	if (key == p->data)
		return p;
	return RLsearch(p->next, key);
}
void Insert(struct Node *p, int index, int x)
{
	struct Node *t;
	int i;

	if (index < 0 || index > count(p))
		return;

	t = new Node;
	t->data = x;
	if (index == 0)
	{
		t->next = first;
		first = t;
	}
	else
	{
		for (i = 0; i < index - 1; i++)
			p = p->next;
		t->next = p->next;
		p->next = t;
	}
}

void SortedInsert(struct Node *p, int x)
{
	struct Node *t, *q = NULL;
	t = new Node;
	t->data = x;
	t->next = NULL;

	if (first == NULL)
		first = t;
	else
	{
		while (p && p->data < x)
		{
			q = p;
			p = p->next;
		}
		if (p == first)
		{
			t->next = first;
			first = t;
		}
		else
		{
			t->next = q->next;
			q->next = t;
		}
	}
}

int Delete(struct Node *p, int index)
{
	struct Node *q = nullptr;
	int x = -1;
	if (index < 1 || index > count(p))
		return -1;
	if (index == 1)
	{
		q = first;
		first = first->next;
		x = q->data;
		delete p;
		return x;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			q = p;
			p = p->next;
		}

		q->next = p->next;
		x = p->data;
		delete p;
		return x;
	}
}
int isSorted(struct Node *p)
{
	int x = INT_MIN;
	while (p)
	{
		if (p->data < x)
		{
			return 0;
		}
		x = p->data;
		p = p->next;
	}
	return 1;
}

void RemoveDuplicates(struct Node *p)
{
	struct Node *q = p->next;

	while (q)
	{
		if (p->data != q->data)
		{
			p = q;
			q = q->next;
		}
		else
		{
			p->next = q->next;
			delete q;
			q = p->next;
		}
	}
}
void ReverseArray(struct Node *p)
{
	int *A;
	struct Node *q = p;
	A = new int(count(p));
	int i = 0;

	while (q)
	{
		A[i] = q->data;
		q = q->next;
		i++;
	}
	q = p;
	i--;
	while (q)
	{
		q->data = A[i];
		q = q->next;
		i--;
	}
}
void Reverse(struct Node *p)
{
	struct Node *r = nullptr, *q = nullptr;
	while (p)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	first = q;
}
void RReverse(struct Node *q, struct Node *p)
{
	if (p)
	{
		RReverse(p, p->next);
		p->next = q;
	}
	else
		first = q;
}

void Concatenate(struct Node *p, struct Node *q)
{
	third = p;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = q;
}
void Merge(struct Node *p, struct Node *q)
{
	struct Node *last;
	if (p->data < q->data)
	{
		third = last = p;
		p = p->next;
		third->next = nullptr;
	}
	else
	{
		third = last = q;
		q = q->next;
		third->next = nullptr;
	}
	while (p && q)
	{
		if (p->data < q->data)
		{
			last->next = p;
			last = p;
			p = p->next;
			last->next = nullptr;
		}
		else
		{
			last->next = q;
			last = q;
			q = q->next;
			last->next = nullptr;
		}
	}
	if (p)
		last->next = p;
	if (q)
		last->next = q;
}

int isloop(struct Node *f)
{
	struct Node *p, *q;
	p = q = f;
	do
	{
		p = p->next;
		q = q->next;
		q = q ? q->next : q;
	} while (p && q && p != q);
	if (p == q)
		return 1;
	else
		return 0;
}
int main(int argc, char **argv)
{
	struct Node *t1, *t2;
	int A[] = {3, 5, 7, 10, 25};
	// int B[] = {1, 2, 3, 6, 8};
	create(A, 5);

	t1 = first->next->next;
	t2 = first->next->next->next->next;
	t2->next = t1;

	// create2(B, 5);
	// Display(first);
	// Display(second);
	// Concatenate(first,second);
	// Merge(first, second);
	// Concatenate(second,first);
	// Display(third);
	// Display(third);
	// cout<<Rcount(first)<<endl;
	// cout<<Rsum(first)<<endl;
	// cout<<max(first)<<endl;
	// cout<<Rmax(first)<<endl;
	cout << isloop(first) << endl;
	// struct Node *temp;
	// temp=Lsearch(first,25);
	// if(temp)
	// cout<<temp->data<<endl;
	// SortedInsert(first, 1);
	// SortedInsert(first, 25);
	// // Insert(first,5,10);
	// Display(first);

	// Delete(first,4);
	// Delete(first,1);
	// Display(first);
	// cout<<isSorted(first);
	return 0;
}
