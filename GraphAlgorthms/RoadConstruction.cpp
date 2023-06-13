#include <bits/stdc++.h>
#define N (int)(1e5 + 5)
using namespace std;

int Size[N];
int parent[N];
int max_value;
int cc;

void make(int u)
{
    Size[u] = 1;
    parent[u] = u;
}

int find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}

void Union(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u != v)
    {
        if (Size[v] > Size[u])
        {
            swap(u, v);
        }
        Size[u] += Size[v];
        parent[v] = u;
        cc--;
        max_value = max(max_value, Size[u]);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        make(i);
    max_value = 1;
    cc = n;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        Union(x, y);
        cout << cc << " " << max_value << endl;
    }
    return 0;
}