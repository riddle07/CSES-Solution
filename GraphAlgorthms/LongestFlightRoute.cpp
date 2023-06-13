#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[x].push_back(make_pair(y, -1));
    }
    priority_queue<pair<int, int>> pq;
    vector<int> d(n, 0);
    vector<int> p(n, -1);
    d[0] = 0;
    pq.push({0, 0});
    while (!pq.empty())
    {
        int crt_n = pq.top().second;
        int crt_d = pq.top().first;
        pq.pop();
        for (auto x : graph[crt_n])
        {
            if (d[x.first] > crt_d + x.second)
            {
                d[x.first] = crt_d + x.second;
                p[x.first] = crt_n;
                pq.push({d[x.first], x.first});
            }
        }
    }
    if (d[n - 1] == 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << d[n - 1] * -1 + 1 << endl;
    int start = n - 1;
    vector<int> path;
    while (start != -1)
    {
        path.push_back(start);
        start = p[start];
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}