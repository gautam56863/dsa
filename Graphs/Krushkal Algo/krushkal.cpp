#include <iostream>
using namespace std;
#define I 32767 // Infinity
#define n 7     // # of vertices in Graph
#define e 9     // # of edges in Graph

int edges[3][9] = {{1, 1, 2, 2, 3, 4, 4, 5, 5},
                   {2, 6, 3, 7, 4, 5, 7, 6, 7},
                   {25, 5, 12, 10, 8, 16, 14, 20, 18}};
int set[n + 1] = {-1, -1, -1, -1, -1, -1, -1, -1};
int t[2][n - 1];
int included[9] = {0};
void MyUion(int u, int v)
{
    if (set[u] < set[v])
    {
        set[u] += set[v];
        set[v] = u;
    }
    else
    {
        set[v] += set[u];
        set[u] = v;
    }
}
int find(int u)
{
    int x = u;
    int v = 0;

    while (set[x] > 0)
    {
        x = set[x];
    }

    while (u != x)
    {
        v = set[u];
        set[u] = x;
        u = v;
    }
    return x;
}

int main()
{
    int i = 0, j, u, v, min = I, k;

    while (i < n - 1)
    {
        min = I;
        for (j = 0; j < e; j++)
        {
            if (included[j] == 0 && edges[2][j] < min)
            {
                min = edges[2][j];
                u = edges[0][j];
                v = edges[1][j];
                k = j;
            }
        }

        if (find(u) != find(v))
        {
            t[0][i] = u;
            t[1][i] = v;
            MyUion(find(u), find(v));
            i++;
        }
        included[k] = 1;
    }

    for (i = 0; i < n - 1; i++)
    {
        cout << "( " << t[0][i] << "," << t[1][i] << " )" << endl;
    }

    return 0;
}