#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        long long z;
        cin >> z;
        graph[x].push_back(make_pair(y, z));
    }
    vector<long long> d(n, LLONG_MAX);
    priority_queue<pair<long long, int>> pq;
    d[0] = 0;
    pq.push(make_pair(0, 0));
    vector<int> p(n, -1);
    while (!pq.empty())
    {
        int crt_node = pq.top().second;
        long long crt_d = pq.top().first;
        pq.pop();
        for (auto x : graph[crt_node])
        {
            if (d[x.first] > x.second + crt_d)
            {
                d[x.first] = x.second + crt_d;
                p[x.first] = crt_node;
                pq.push(make_pair(d[x.first], x.first));
            }
        }
    }
    int start = n - 1;
    long long max_val = LLONG_MIN;
    while (p[start] != -1)
    {
        long long crt_val = -1;
        for (auto x : graph[p[start]])
        {
            if (x.first == start)
            {
                crt_val = x.second;
                break;
            }
        }
        max_val = max(max_val, crt_val);
        start = p[start];
    }
    long long ans = d[n - 1] - (max_val + 1) / 2;
    cout << ans << endl;
    return 0;
}