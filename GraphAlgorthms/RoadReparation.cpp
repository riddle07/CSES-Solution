#include <bits/stdc++.h>
#define N_max (int)(1e5 + 5)

using namespace std;

int parent[N_max];
int Size[N_max];
void make(int v)
{
    parent[v] = v;
    Size[v] = 1;
}

int find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

void Union(int v, int u)
{
    v = find(v);
    u = find(u);
    if (u != v)
    {
        if (Size[u] > Size[v])
            swap(u, v);
        parent[u] = v;
        Size[v] += Size[u];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<long long, pair<int, int>>> e;
    for (int i = 0; i < m; i++)
    {
        long long z;
        int u, v;
        cin >> u >> v;
        cin >> z;
        e.push_back({z, {u, v}});
    }
    sort(e.begin(), e.end());
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    long long ans = 0;
    for (int i = 0; i < e.size(); i++)
    {
        long long wt = e[i].first;
        int u = e[i].second.first, v = e[i].second.second;
        if (find(u) == find(v))
            continue;
        Union(u, v);
        ans += wt;
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = find(i);
        if (parent[i] == i)
            count++;
    }
    if (count == 1)
        cout << ans << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}